<?php
/**
 * @file
 * quiz_extra.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function quiz_extra_default_rules_configuration() {
  $items = array();
  $items['rules_quiz_complete'] = entity_import('rules_config', '{ "rules_quiz_complete" : {
      "LABEL" : "Quiz Complete",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "flag", "quiz" ],
      "ON" : [ "quiz_complete" ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "course_item_complete",
            "node" : [ "quiz" ],
            "flagging_user" : [ "current-user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
