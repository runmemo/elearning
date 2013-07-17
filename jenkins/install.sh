#!/bin/bash

# Script for installing e-learning web-site

# Notes:
# 1) For instructions for installing drush on different OS, please, visit https://drupal.org/node/1791676
# 2) SSH authentication method is used to clone git repository, so there is a need to have ssh key for
# the user, from whom this file is called.
# For more details, please, visit https://help.github.com/articles/generating-ssh-keys
# 3) In order to work with MySQL from this file, there is a need to have configuration file.
# It should be placed in home directory, e.g. /home/%username%/.my.conf and
# should be writable only by owner (access mode 400 or 600).
# This file should contain at least username and password for the user with administrative rights
# in the following way
# [client]
# user=user_name
# password=user_password
# Please, visit http://dev.mysql.com/doc/refman/5.0/en/option-files.html for more info.

# Parameters
# $1 - folder, in witch site's folder should be located
# $2 - folder, in witch site should be located, DB name, DB user
# $3 - full path to mysql config file. See item 3) of Notes section.

# Variables
BTICK='`'
EXPECTED_ARGS=3
PARENT_FOLDER=$1;
SUBFOLDER=$2;
DB_NAME=$2;
DB_USER=$2;
DB_CONF=$3;

# generate DB password
DB_PASS=$(date | sha256sum | base64 | head -c 16 );

# check parameters
if [ $# -ne $EXPECTED_ARGS ]
then
echo "Not enough parameters"
exit
fi

# check mysql
if ! type -p mysql > /dev/null;
then
echo "Please, make sure MySQL is installed"
exit
fi

MYSQL=`which mysql`
Q1="CREATE DATABASE IF NOT EXISTS ${BTICK}$DB_NAME${BTICK};"
Q2="GRANT ALL ON ${BTICK}DB_NAME${BTICK}.* TO '$DB_USER'@'localhost' IDENTIFIED BY '$DB_PASS';"
Q3="FLUSH PRIVILEGES;"
SQL="${Q1}${Q2}${Q3}"
$MYSQL --defaults-file=$DB_CONF -e "$SQL"
echo "Database and user have been created"

# check if drush is installed
if ! type -p drush > /dev/null;
then
pear channel-discover pear.drush.org
pear install drush/drush
echo "drush has been installed"
else
echo "drush is already installed"
drush --version
fi
echo "downloading drupal..."
drush dl drupal --destination=/$PARENT_FOLDER --drupal-project-rename=$SUBFOLDER -y
git clone --no-checkout git@github.com:runmemo/elearning.git $PARENT_FOLDER/$SUBFOLDER/repo
mv $PARENT_FOLDER/$SUBFOLDER/repo/.git $PARENT_FOLDER/$SUBFOLDER
rm -R $PARENT_FOLDER/$SUBFOLDER/repo
cd $PARENT_FOLDER/$SUBFOLDER
git reset --hard HEAD
drush si coursehub --account-name=admin --account-pass=admin --db-url=mysql://$DB_USER:$DB_PASS@localhost/$DB_NAME -y
exit
