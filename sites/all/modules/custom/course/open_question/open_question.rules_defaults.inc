<?php

/**
 * @file
 * course.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function open_question_default_rules_configuration() {
  $items = array();
  $items['open_question_answered'] = entity_import('rules_config', 
  '{ "rules_open_question_answered" : {
        "LABEL" : "Open Question Answered",
        "PLUGIN" : "reaction rule",
        "REQUIRES" : [ "flag", "open_question" ],
        "ON" : [ "open_question_answered" ],
        "DO" : [
          { "flag_flagnode" : {
              "flag" : "course_item_complete",
              "node" : [ "open-question" ],
              "flagging_user" : [ "asnwered-by" ],
              "permission_check" : 0
            }
          }
        ]
      }
    }');
  return $items;
}
