<?php
/**
 * @file
 * subscriptions_question.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function subscriptions_node_default_rules_configuration() {
  $items = array();
  $items['rules_follow_node'] = entity_import('rules_config', '{ "rules_follow_node" : {
      "LABEL" : "follow node",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "subscriptions_rules", "flag" ],
      "ON" : [ "flag_flagged_follow_node" ],
      "DO" : [
        { "subscriptions_rules_add_user_content" : {
            "node" : [ "flagged-node" ],
            "user" : [ "flagging-user" ],
            "type" : "comment",
            "send_interval" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_unfollow_node'] = entity_import('rules_config', '{ "rules_unfollow_node" : {
      "LABEL" : "unfollow node",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "subscriptions_rules", "flag" ],
      "ON" : [ "flag_unflagged_follow_node" ],
      "DO" : [
        { "subscriptions_rules_remove_user_content" : {
            "node" : [ "flagged-node" ],
            "user" : [ "flagging-user" ],
            "type" : "comment",
            "send_interval" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
