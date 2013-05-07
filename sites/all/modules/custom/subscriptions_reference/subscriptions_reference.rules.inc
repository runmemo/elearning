<?php

/**
 * @file
 * subscriptions_reference.rules.inc
 * Contains rules actions for subscribing to nodes via reference fields
 */

/**
 * Implements hook_rules_action_info() on behalf of the node module.
 */
function subscriptions_reference_rules_action_info() {
  $base = array(
    'type' => 'subscriptions',
    'parameter' => array(
      'node' => array('type' => 'node', 'label' => t('Node')),
      'user' => array('type' => 'user', 'label' => t('User')),
    ),
    'group' => t('Subscriptions'),
    'access callback' => 'subscriptions_reference_subscribe_access',
  );

  // Action subsribe a user to a content
  $items['subscriptions_reference_subscribe_action'] = array(
    'label' => t('Subscribe user to referencing nodes'),
    'base' => 'subscriptions_reference_subscribe',
      ) + $base;

  // Action unsubsribe a user to a content
  $items['subscriptions_reference_unsubscribe_action'] = array(
    'label' => t('Unsubscribe user from referencing nodes'),
    'base' => 'subscriptions_reference_unsubscribe',
      ) + $base;

  return $items;
}

/**
 * Rules subscribe action callback
 */
function subscriptions_reference_subscribe($node, $user) {
  $reference_field = subscriptions_reference_get_field_name($node, 'parent');
  if (!$reference_field)
    return;
  // write subscription to database
  subscriptions_write_subscription(REFERENCE_MODULE, $reference_field, $node->nid, -1, $user->uid);
}


/**
 * Rules unsubscribe action callback
 */
function subscriptions_reference_unsubscribe($node, $user) {
  $reference_field = subscriptions_reference_get_field_name($node, 'parent');
  if (!$reference_field) return;
  
  db_delete('subscriptions')
      ->condition('module', REFERENCE_MODULE)
      ->condition('field', $reference_field)
      ->condition('value', $node->nid)
      ->condition('author_uid', -1)  // DEBUG $node->uid,
      ->condition('recipient_uid', $user->uid)
      ->execute();
}