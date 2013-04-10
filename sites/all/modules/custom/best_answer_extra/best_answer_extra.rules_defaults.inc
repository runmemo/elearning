<?php

/**
 * @file
 * best_answer_extra.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function best_answer_extra_default_rules_configuration() {
  $items = array();
  $items['rules_best_answer_flagged'] = entity_import('rules_config',
    '{ "rules_best_answer_flagged" : {
      "LABEL" : "User flags answer under best_answer flag",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "open_question", "flag" ],
      "ON" : [ "flag_flagged_best_answer" ],
      "DO" : [
        { "open_question_best_answer" : {
            "flag" : "best_answer",
            "flagging_user" : [ "flagging_user" ],
            "node" : [ "flagged-node" ]
          }
        }
      ]
    }
  }');
  $items['rules_best_answer_unflagged'] = entity_import('rules_config',
    '{ "rules_best_answer_unflagged" : {
      "LABEL" : "User unflags answer under best_answer flag",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "open_question", "flag" ],
      "ON" : [ "flag_unflagged_best_answer" ],
      "DO" : [
        { "open_question_best_answer" : {
            "flag" : "best_answer",
            "flagging_user" : [ "flagging_user" ],
            "node" : [ "flagged-node" ]
          }
        }
      ]
    }
  }');
  $items['rules_user_selects_best_answer_extra'] = entity_import('rules_config', '{ "rules_user_selects_best_answer_extra" : {
      "LABEL" : "User selects a best answer (custom)",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Answers Userpoints" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "best_answer" ],
      "ON" : [ "best_answer_set" ],
      "IF" : [
        { "NOT user_has_role" : { "account" : [ "answer:author" ], "roles" : { "value" : { "1" : "1" } } } },
        { "AND" : [] },
        { "NOT data_is" : { "data" : [ "question:author:uid" ], "value" : [ "answer:author:uid" ] } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "answer:author" ],
            "points" : "15",
            "tid" : "1",
            "entity" : [ "question" ],
            "description" : "Your answer has been selected as the best answer",
            "operation" : "Select Best Answer",
            "reference" : "[question:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        },
        { "userpoints_action_grant_points" : {
            "user" : [ "site:current-user" ],
            "points" : "2",
            "tid" : "1",
            "entity" : [ "question" ],
            "description" : "You selected a best answer",
            "operation" : "Select Best Answer",
            "reference" : "[question:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_user_unselects_best_answer_extra'] = entity_import('rules_config', '{ "rules_user_unselects_best_answer_extra" : {
      "LABEL" : "User unselects a prior best answer (custom)",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Answers Userpoints" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "best_answer" ],
      "ON" : [ "best_answer_unset" ],
      "IF" : [
        { "NOT user_has_role" : { "account" : [ "answer:author" ], "roles" : { "value" : { "1" : "1" } } } },
        { "AND" : [] },
        { "NOT data_is" : { "data" : [ "question:author:uid" ], "value" : [ "answer:author:uid" ] } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "answer:author" ],
            "points" : "-15",
            "tid" : "1",
            "entity" : [ "question" ],
            "description" : "Your answer has been unselected as the best answer",
            "operation" : "Retract Best Answer",
            "reference" : "[question:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        },
        { "userpoints_action_grant_points" : {
            "user" : [ "site:current-user" ],
            "points" : "-2",
            "tid" : "1",
            "entity" : [ "question" ],
            "description" : "You retracted a best answer",
            "operation" : "Retract Best Answer",
            "reference" : "[question:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  return $items;
}
