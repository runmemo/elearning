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
  $items['rules_user_unselects_best_answer_extra'] = entity_import('rules_config', '{ "rules_user_unselects_best_answer_extra" : {
    "LABEL" : "User unselects a prior best answer (custom)",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "Answers Userpoints" ],
    "REQUIRES" : [ "rules", "userpoints_rules", "flag", "best_answer" ],
    "ON" : [ "best_answer_unset" ],
    "DO" : [
      { "flag_unflagnode" : {
          "flag" : "best_answer",
          "node" : [ "answer" ],
          "flagging_user" : [ "question:author" ],
          "permission_check" : 0
        }
      }
    ]
  }
}');
  return $items;
}
