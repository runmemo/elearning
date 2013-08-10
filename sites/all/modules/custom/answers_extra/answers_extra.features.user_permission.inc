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
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'vud',
  );

  // Exported permission: use vote up/down.
  $permissions['use vote up/down'] = array(
    'name' => 'use vote up/down',
    'roles' => array(
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'vud',
  );

  // Exported permission: edit own answer content.
  $permissions['create answer content'] = array(
    'name' => 'create answer content',
    'roles' => array(
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own answer content.
  $permissions['edit own answer content'] = array(
    'name' => 'edit own answer content',
    'roles' => array(
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own answer content'.
  $permissions['delete own answer content'] = array(
    'name' => 'delete own answer content',
    'roles' => array(
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own answer content.
  $permissions['create question content'] = array(
    'name' => 'create question content',
    'roles' => array(
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own answer content.
  $permissions['edit own question content'] = array(
    'name' => 'edit own question content',
    'roles' => array(
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own question content'.
  $permissions['delete own question content'] = array(
    'name' => 'delete own question content',
    'roles' => array(
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  return $permissions;
}
