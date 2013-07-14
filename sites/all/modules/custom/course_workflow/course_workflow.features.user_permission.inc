<?php
/**
 * @file
 * course_workflow.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function course_workflow_user_default_permissions() {
  $permissions = array();

  // Exported permission: access any unpublished course.
  $permissions['access any unpublished course'] = array(
    'name' => 'access any unpublished course',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'course_access',
  );

  // Exported permission: access own unpublished course.
  $permissions['access own unpublished course'] = array(
    'name' => 'access own unpublished course',
    'roles' => array(
      'administrator' => 'administrator',
      'teacher' => 'teacher',
    ),
    'module' => 'course_access',
  );

  return $permissions;
}
