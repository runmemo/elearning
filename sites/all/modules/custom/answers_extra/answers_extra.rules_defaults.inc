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
  return $items;
}
