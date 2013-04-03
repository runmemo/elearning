<?php
/**
 * @file
 * lesson.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function lesson_default_rules_configuration() {
  $items = array();
  $items['rules_lesson_complete'] = entity_import('rules_config', 
    '{ "rules_lesson_complete" : {
        "LABEL" : "Lesson Complete",
        "PLUGIN" : "reaction rule",
        "REQUIRES" : [ "flag", "lesson" ],
        "ON" : [ "lesson_complete" ],
        "DO" : [
          { "flag_flagnode" : {
              "flag" : "course_item_complete",
              "node" : [ "lesson" ],
              "flagging_user" : [ "current-user" ],
              "permission_check" : 0
            }
          }
        ]
      }
    }');
  return $items;
}