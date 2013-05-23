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

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'not validated user' => 'not validated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
