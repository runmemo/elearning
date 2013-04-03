<?php
/**
 * @file
 * course.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function course_default_rules_configuration() {
  $items = array();
  $items['rules_lesson_video_complete'] = entity_import('rules_config', '{ "rules_lesson_video_complete" : {
      "LABEL" : "Lesson Video Complete",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "flag", "lesson" ],
      "ON" : [ "video_complete_rule_event" ],
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
