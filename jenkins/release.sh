#pull repo on test instance
cd ../var/www/html/coursehub
su coursehub
git pull
drush updatedb -y

#run tests
/bin/sh -x /var/www/html/courshub/jenkins/tests_run.sh

