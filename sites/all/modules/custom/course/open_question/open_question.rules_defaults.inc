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
  $items['rules_open_question_viewed'] = entity_import('rules_config', '{ "rules_open_question_viewed" : {
      "LABEL" : "Open Question Viewed",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "node_view" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "open_question" : "open_question" } }
          }
        }
      ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "course_item_complete",
            "node" : [ "node" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
