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
  $items['rules_lesson_item_complete_flagged'] = entity_import('rules_config', '{ "rules_lesson_item_complete_flagged" : {
      "LABEL" : "Lesson item complete flagged",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Lesson" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "flag" ],
      "ON" : [ "flag_flagged_course_item_complete" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "lesson" : "lesson" } }
          }
        }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "flagging-user" ],
            "points" : "1",
            "tid" : "0",
            "entity" : [ "flagged-node" ],
            "description" : "Student will get 1 point for watching the video \\/ completion of the lesson.",
            "operation" : "Insert",
            "display" : 1,
            "moderate" : "default"
          }
        }
      ]
    }
  }');
  $items['rules_lesson_item_complete_unflagged'] = entity_import('rules_config', '{ "rules_lesson_item_complete_unflagged" : {
      "LABEL" : "Lesson item complete unflagged",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Lesson" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "flag" ],
      "ON" : [ "flag_unflagged_course_item_complete" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "lesson" : "lesson" } }
          }
        }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "flagging-user" ],
            "points" : "-1",
            "tid" : "0",
            "entity" : [ "flagged-node" ],
            "description" : "Student will loose 1 point if completed lesson marked uncompleted.",
            "operation" : "Remove",
            "display" : 1,
            "moderate" : "default"
          }
        }
      ]
    }
  }');
  return $items;
}
