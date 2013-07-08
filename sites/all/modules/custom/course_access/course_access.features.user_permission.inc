<?php
/**
 * @file
 * course_access.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function course_access_user_default_permissions() {
  $permissions = array();

  // Exported permission: view any unpublished course.
  $permissions['view any unpublished course'] = array(
    'name' => 'view any unpublished course',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'course_access',
  );

  // Exported permission: view own unpublished course.
  $permissions['view own unpublished course'] = array(
    'name' => 'view own unpublished course',
    'roles' => array(
      'administrator' => 'administrator',
      'teacher' => 'teacher',
    ),
    'module' => 'course_access',
  );

  return $permissions;
}
