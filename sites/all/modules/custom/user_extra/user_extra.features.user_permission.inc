<?php
/**
 * @file
 * user_extra.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function user_extra_user_default_permissions() {
  $permissions = array();

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  return $permissions;
}
