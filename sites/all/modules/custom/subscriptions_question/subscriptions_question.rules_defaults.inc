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
      "LABEL" : "follow question",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "rules", "flag" ],
      "ON" : [ "flag_flagged_follow_question" ],
      "DO" : [
        { "php_eval" : { "code" : "  subscriptions_write_subscription(\\u0027node\\u0027, \\u0027field_answer_question\\u0027, $flagged_node-\\u003Enid, -1, $flagging_user-\\u003Euid, 1, 1, 1);\\r\\n" } }
      ]
    }
  }');
  $items['rules_unfollow_question'] = entity_import('rules_config', '{ "rules_unfollow_question" : {
      "LABEL" : "unfollow question",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "rules", "flag" ],
      "ON" : [ "flag_unflagged_follow_question" ],
      "DO" : [
        { "php_eval" : { "code" : "subscriptions_delete($flagging_user-\\u003Euid, \\u0027node\\u0027, \\u0027field_answer_question\\u0027, $flagged_node-\\u003Enid, -1);\\r\\n" } }
      ]
    }
  }');
  return $items;
}
