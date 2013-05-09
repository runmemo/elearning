<?php

/**
 * @file
 * open_question.rules_defaults.inc
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
            { "flag_unflagnode" : {
                "flag" : "course_item_complete",
                "node" : [ "open-question" ],
                "flagging_user" : [ "answered-by" ],
                "permission_check" : 0
              }
            },
            { "flag_flagnode" : {
                "flag" : "course_item_complete",
                "node" : [ "open-question" ],
                "flagging_user" : [ "answered-by" ],
                "permission_check" : 0
              }
            }
          ]
      }
    }');
  $items['rules_feedback_marked_as_useful'] = entity_import('rules_config',
    '{ "rules_feedback_marked_as_useful" : {
      "LABEL" : "Feedback marked as useful",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "userpoints_rules", "flag" ],
      "ON" : [ "flag_flagged_opaf_useful" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "open_question_feedback" : "open_question_feedback" } }
          }
        }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "flagged-node:author" ],
            "points" : "10",
            "tid" : "1",
            "entity" : [ "flagged-node:field-open-question-answer" ],
            "description" : "Answer author marked feedback #[flagged-node:nid] as useful",
            "operation" : "Mark Useful",
            "reference" : "[flagged-node:field-open-question-answer]",
            "display" : 0,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_feedback_unmarked_as_useful'] = entity_import('rules_config',
    '{ "rules_feedback_unmarked_as_useful" : {
      "LABEL" : "Feedback unmarked as useful",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "userpoints_rules", "flag" ],
      "ON" : [ "flag_unflagged_opaf_useful" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "open_question_feedback" : "open_question_feedback" } }
          }
        }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "flagged-node:author" ],
            "points" : "-10",
            "tid" : "1",
            "entity" : [ "flagged-node:field-open-question-answer" ],
            "description" : "Answer author unmarked feedback #[flagged-node:nid] as useful",
            "operation" : "Unmark Useful",
            "reference" : "[flagged-node:field-open-question-answer]",
            "display" : 0,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_subscribe_author_to_open_question_answer'] = entity_import('rules_config', '{ "rules_subscribe_author_to_open_question_answer" : {
      "LABEL" : "Subscribe Author to Open Question Answer",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "subscriptions_reference" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "open_question_answer" : "open_question_answer" } }
          }
        }
      ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "subscriptions_reference_flag",
            "node" : [ "node" ],
            "flagging_user" : [ "node:author" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
