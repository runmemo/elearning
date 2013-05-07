<?php
/**
 * @file
 * subscriptions_question.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function subscriptions_node_user_default_permissions() {
  $permissions = array();

  // Exported permission: flag follow_nodes.
  $permissions['flag follow_node'] = array(
    'name' => 'flag follow_node',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: unflag follow_nodes.
  $permissions['unflag follow_node'] = array(
    'name' => 'unflag follow_node',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
