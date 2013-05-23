<?php
/**
 * @file
 * lesson.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function lesson_user_default_permissions() {
  
  $permissions = array();

  // Exported permission: create notes content.
  $permissions['create notes content'] = array(
    'name' => 'create notes content',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own notes content.
  $permissions['delete own notes content'] = array(
    'name' => 'delete own notes content',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own notes content.
  $permissions['edit own notes content'] = array(
    'name' => 'edit own notes content',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  return $permissions;
}
