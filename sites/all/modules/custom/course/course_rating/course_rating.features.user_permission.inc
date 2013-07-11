<?php
/**
 * @file
 * course_rating.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function course_rating_user_default_permissions() {
  $permissions = array();

  // Exported permission: rate content.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fivestar',
  );

  return $permissions;
}
