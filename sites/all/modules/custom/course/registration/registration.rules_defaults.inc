<?php
/**
 * @file
 * registration.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function registration_default_rules_configuration() {
  $items = array();
  $items['rules_course_registration_role'] = entity_import('rules_config', '{ "rules_course_registration_role" : {
      "LABEL" : "Course registration role",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "php", "logintoboggan_rules" ],
      "ON" : [ "logintoboggan_validated" ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "5" : "5" } } } },
        { "php_eval" : { "code" : "registration_user_validated($account);" } }
      ]
    }
  }');
  return $items;
}
