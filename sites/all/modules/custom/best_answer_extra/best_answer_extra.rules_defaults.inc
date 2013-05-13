<?php

/**
 * @file
 * best_answer_extra.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function best_answer_extra_default_rules_configuration() {
  $rules = array();
  
  $rules['rules_flag_answers_best_answer'] = entity_import('rules_config', '{ "rules_flag_answers_best_answer" : {
    "LABEL" : "Answer flagged as best",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "answers" ],
    "REQUIRES" : [ "userpoints_rules", "flag" ],
    "ON" : [ "flag_flagged_best_answer" ],
    "IF" : [
      { "NOT data_is" : { "data" : [ "flagging-user" ], "value" : [ "flagged-node:author" ] } }
    ],
    "DO" : [
      { "userpoints_action_grant_points" : {
          "user" : [ "flagged-node:author" ],
          "points" : "15",
          "tid" : "0",
          "entity" : [ "" ],
          "operation" : "Answer selected as best",
          "display" : 1,
          "moderate" : "default"
        }
      },
      { "userpoints_action_grant_points" : {
          "user" : [ "flagging-user" ],
          "points" : "2",
          "tid" : "0",
          "entity" : [ "" ],
          "operation" : "Selected best answer",
          "display" : 1,
          "moderate" : "default"
      }}
    ]
  }}');
  
  $rules['rules_unflag_answers_best_answer'] = entity_import('rules_config', '{ "rules_unflag_answers_best_answer" : {
    "LABEL" : "Best answer is unflagged",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "answers" ],
    "REQUIRES" : [ "userpoints_rules", "flag" ],
    "ON" : [ "flag_unflagged_best_answer" ],
    "IF" : [
      { "NOT data_is" : { "data" : [ "flagging-user" ], "value" : [ "flagged-node:author" ] } }
    ],
    "DO" : [
      { "userpoints_action_grant_points" : {
          "user" : [ "flagged-node:author" ],
          "points" : "-15",
          "tid" : "0",
          "entity" : [ "" ],
          "operation" : "Unselected answer as best",
          "display" : 1,
          "moderate" : "default"
        }
      },
      { "userpoints_action_grant_points" : {
          "user" : [ "flagging-user" ],
          "points" : "-2",
          "tid" : "0",
          "entity" : [ "" ],
          "operation" : "Unselected best answer",
          "display" : 1,
          "moderate" : "default"
      }}
    ]
  }}');
  
  return $rules;
}
