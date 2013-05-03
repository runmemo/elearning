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
            "flag" : "follow_question",
            "node" : [ "node" ],
            "flagging_user" : [ "node:author" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  $items['rules_follow_lesson_items'] = entity_import('rules_config', '{ "rules_follow_lesson_items" : {
      "LABEL" : "follow lesson items",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "subscriptions_rules", "flag" ],
      "ON" : [ "flag_flagged_follow_lesson_item" ],
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
  $items['rules_unfollow_lesson_items'] = entity_import('rules_config', '{ "rules_unfollow_lesson_items" : {
      "LABEL" : "unfollow lesson items",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "subscriptions_rules", "flag" ],
      "ON" : [ "flag_unflagged_follow_lesson_item" ],
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
