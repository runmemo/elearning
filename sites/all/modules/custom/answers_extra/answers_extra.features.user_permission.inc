<?php
/**
 * @file
 * answers_extra.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function answers_extra_user_default_permissions() {
  $permissions = array();
  
  // Exported permission: reset vote up/down votes.
  $permissions['reset vote up/down votes'] = array(
    'name' => 'reset vote up/down votes',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'vud',
  );

  // Exported permission: use vote up/down.
  $permissions['use vote up/down'] = array(
    'name' => 'use vote up/down',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'vud',
  );

  return $permissions;
}
