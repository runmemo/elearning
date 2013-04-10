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
  return $items;
}
