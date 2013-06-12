#!/bin/sh -x

#/**
# * @file tests_run.sh
# * @author Leonid Bogomolov
# * @version 1.0
# *
# * @section DESCRIPTION
# *
# * This script runs "drush test-run" for every test in test_list file
# * and save results as xml.
# *
# */

rm -rf /tmp/tests/*
mkdir -p /tmp/tests/
chmod 777 /tmp/tests/

cd /var/www/html/coursehub

alias drush="drush -l test.coursehub.ru"
drush status
drush updatedb --yes
drush cache-clear all
for testname in `cat ./jenkins/tests_list`; do
drush test-run --xml=/tmp/tests/ ${testname}
  if [ $? -ne 0 ]; then
    echo "Failed to run test ${testname}"
    exit 1
  fi
done