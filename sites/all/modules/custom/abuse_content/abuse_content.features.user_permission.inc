<?php
/**
 * @file
 * abuse_content.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function abuse_content_user_default_permissions() {
  $permissions = array();

  // Exported permission: flag abuse_content.
  $permissions['flag abuse_content'] = array(
    'name' => 'flag abuse_content',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'flag',
  );

  // Exported permission: unflag abuse_content.
  $permissions['unflag abuse_content'] = array(
    'name' => 'unflag abuse_content',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
