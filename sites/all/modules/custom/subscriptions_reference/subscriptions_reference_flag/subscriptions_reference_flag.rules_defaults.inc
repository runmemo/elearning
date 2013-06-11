<?php
/**
 * @file
 * subscriptions_reference_flag.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function subscriptions_reference_flag_default_rules_configuration() {
  $items = array();
  
  $fields = _subscriptions_reference_available_fields();
  // Here we separate rules for different content types for visibility purposes.
  // Aslo this will allow admin to add custom granular control to the rules.
  foreach ($fields as $field) {
    // Get content type that user can follow with this rule
    $type = $field['parent'];
    // Add follow rule for current content type.
    $items['rules_follow_' . $type . '_reference'] = entity_import('rules_config', '{ "rules_follow_' . $type . '_reference" : {
        "LABEL" : "Follow ' . node_type_get_name($type) . ' by Reeference",
        "PLUGIN" : "reaction rule",
        "REQUIRES" : [ "subscriptions_reference", "flag" ],
        "ON" : [ "flag_flagged_subscriptions_reference_flag" ],
        "DO" : [
          { "subscriptions_reference_subscribe_action" : { "node" : [ "flagged-node" ], "user" : [ "flagging-user" ] } }
        ]
      }
    }');
    // Add unfollow rule for current content type.
    $items['rules_unfollow_' . $type . '_reference'] = entity_import('rules_config', '{ "rules_unfollow_' . $type . '_reference" : {
        "LABEL" : "Unfollow ' . node_type_get_name($type) . ' by Reference",
        "PLUGIN" : "reaction rule",
        "REQUIRES" : [ "subscriptions_reference", "flag" ],
        "ON" : [ "flag_unflagged_subscriptions_reference_flag" ],
        "DO" : [
          { "subscriptions_reference_unsubscribe_action" : { "node" : [ "flagged-node" ], "user" : [ "flagging-user" ] } }
        ]
      }
    }');
    
  }
 
  return $items;
}
