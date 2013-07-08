#!/bin/bash
# Script for installing e-learning web-site

# Parameters
# $1 - folder, in witch site's folder should be located
# $2 - folder, in witch site should be located
# $3 - DB name
# $4 - DB user
# $5 - DB user password

BTICK='`'
EXPECTED_ARGS=5
PARENT_FOLDER=$1;
SUBFOLDER=$2;
DB_NAME=$3;
DB_USER=$4;
DB_PASS=$5;

#check parameters
if [ $# -ne $EXPECTED_ARGS ]
then
echo "Not enough parameters"
exit
fi

#check mysql
if ! type -p mysql > /dev/null;
then
echo "Please, make sure MySQL is installed"
exit
fi

MYSQL=`which mysql`
Q1="CREATE DATABASE IF NOT EXISTS ${BTICK}DB_NAME${BTICK};"
Q2="GRANT ALL ON ${BTICK}DB_NAME${BTICK}.* TO '$DB_USER'@'localhost' IDENTIFIED BY '$DB_PASS';"
Q3="FLUSH PRIVILEGES;"
SQL="${Q1}${Q2}${Q3}"
$MYSQL -uroot -p -e "$SQL"
echo "Database and user have been created"

#create folder
mkdir -p $PARENT_FOLDER/$SUBFOLDER
echo "Folder has been created or already exist"

#check if drush is installed
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
drush dl drupal --destination=/$PARENT_FOLDER --drupal-project-rename=$SUBFOLDER
git clone https://github.com/runmemo/elearning.git $PARENT_FOLDER/$SUBFOLDER/repo
cp -r $PARENT_FOLDER/$SUBFOLDER/repo/* $PARENT_FOLDER/$SUBFOLDER
mv $PARENT_FOLDER/$SUBFOLDER/repo/.git $PARENT_FOLDER/$SUBFOLDER
rm -R $PARENT_FOLDER/$SUBFOLDER/repo
cd $PARENT_FOLDER/$SUBFOLDER
git reset --hard HEAD
drush si coursehub --account-name=admin --account-pass=admin --db-url=mysql://$DB_USER:$DB_PASS@localhost/$DB_NAME
exit
