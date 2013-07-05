#!/bin/bash
# Script for installing e-learning web-site

BTICK='`'
EXPECTED_ARGS=5

# Parameters
# $1 - folder, in witch site's folder should be located
# $2 - folder, in witch site should be located
# $3 - DB name
# $4 - DB user
# $5 - DB user password


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
Q1="CREATE DATABASE IF NOT EXISTS ${BTICK}$3${BTICK};"
Q2="GRANT ALL ON ${BTICK}$3${BTICK}.* TO '$4'@'localhost' IDENTIFIED BY '$5';"
Q3="FLUSH PRIVILEGES;"
SQL="${Q1}${Q2}${Q3}"
$MYSQL -uroot -p -e "$SQL"
echo "Database and user have been created"

#create folder
mkdir -p $1/$2
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
drush dl drupal --destination=/$1 --drupal-project-rename=$2
#clone repo to /repo folder and then just move files to main folder
git clone https://github.com/runmemo/elearning.git $1/$2/repo
cp -R $1/$2/repo/profiles/coursehub $1/$2/profiles
cp -R $1/$2/repo/sites $1/$2
cp -R $1/$2/repo/patches $1/$2
cp -R $1/$2/repo/jenkins $1/$2
cp -R $1/$2/repo/README.md $1/$2
cp -R $1/$2/repo/.gitignore $1/$2
mv $1/$2/repo/.git $1/$2
rm -R $1/$2/repo
cd $1/$2
# git thinks, that files are deleted, so need to reset
git reset --hard HEAD
cd $1/$2
drush si coursehub --account-name=admin --account-pass=admin --db-url=mysql://$4:$5@localhost/$3
exit
