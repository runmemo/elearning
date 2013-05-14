<?php

/**
 * @file
 * answers_extra.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function answers_extra_default_rules_configuration() {
  $items = array();
  // Subscribe author of question to new answers
  $items['rules_subscribe_author_to_question'] = entity_import('rules_config', '{ "rules_subscribe_author_to_question" : {
        "LABEL" : "Subscribe author to question",
        "PLUGIN" : "reaction rule",
        "REQUIRES" : [ "rules", "flag" ],
        "ON" : [ "node_insert" ],
        "IF" : [
          { "node_is_of_type" : {
              "node" : [ "node" ],
              "type" : { "value" : { "question" : "question" } }
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

  $items['rules_answer_voting_points'] = entity_import('rules_config', '{ "rules_answer_voting_points" : {
      "LABEL" : "Answer voting points",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "voting_rules", "userpoints_rules" ],
      "ON" : [ "voting_rules_insert_node" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "answer" : "answer" } } } },
        { "NOT data_is" : { "data" : [ "vote:user" ], "value" : [ "node:author" ] } },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "operator" : "\\u003E", "value" : "0" } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "5",
            "tid" : "0",
            "entity" : [ "vote:entity" ],
            "description" : "Answer vote up.",
            "operation" : "Insert",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_answer_voting_points_revert'] = entity_import('rules_config', '{ "rules_answer_voting_points_revert" : {
      "LABEL" : "Answer voting points revert",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "voting_rules", "userpoints_rules" ],
      "ON" : [ "voting_rules_insert_node" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "answer" : "answer" } } } },
        { "NOT data_is" : { "data" : [ "vote:user" ], "value" : [ "node:author" ] } },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "operator" : "\\u003C", "value" : "0" } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "-5",
            "tid" : "0",
            "entity" : [ "vote:entity" ],
            "description" : "Answer vote down.",
            "operation" : "Remove",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_question_voting_points'] = entity_import('rules_config', '{ "rules_question_voting_points" : {
      "LABEL" : "Question voting points",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "voting_rules", "userpoints_rules" ],
      "ON" : [ "voting_rules_insert_node" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "question" : "question" } }
          }
        },
        { "NOT data_is" : { "data" : [ "vote:user" ], "value" : [ "node:author" ] } },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "operator" : "\\u003E", "value" : "0" } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "5",
            "tid" : "0",
            "entity" : [ "vote:entity" ],
            "description" : "Question vote up.",
            "operation" : "Insert",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_question_voting_points_revert'] = entity_import('rules_config', '{ "rules_question_voting_points_revert" : {
      "LABEL" : "Question voting points revert",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "voting_rules", "userpoints_rules" ],
      "ON" : [ "voting_rules_insert_node" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "question" : "question" } }
          }
        },
        { "NOT data_is" : { "data" : [ "vote:user" ], "value" : [ "node:author" ] } },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "operator" : "\\u003C", "value" : "0" } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "-5",
            "tid" : "0",
            "entity" : [ "vote:entity" ],
            "description" : "Question vote down.",
            "operation" : "Remove",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  return $items;
}
