<?php
/**
 * @file
 * subscriptions_question.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function subscriptions_question_default_rules_configuration() {
  $items = array();
  $items['rules_follow_question'] = entity_import('rules_config', '{ "rules_follow_question" : {
      "LABEL" : "Follow question",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "subscriptions_question", "flag" ],
      "ON" : [ "flag_flagged_follow_question" ],
      "DO" : [
        { "subscriptions_reference_subscribe_action" : { "node" : [ "flagged-node" ], "user" : [ "flagging-user" ] } }
      ]
    }
  }');
  $items['rules_unfollow_question'] = entity_import('rules_config', '{ "rules_unfollow_question" : {
      "LABEL" : "Unfollow question",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "subscriptions_question", "flag" ],
      "ON" : [ "flag_unflagged_follow_question" ],
      "DO" : [
        { "subscriptions_reference_unsubscribe_action" : { "node" : [ "flagged-node" ], "user" : [ "flagging-user" ] } }
      ]
    }
  }');
  return $items;
}
