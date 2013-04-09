<?php
/**
 * @file
 * open_question.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function open_question_user_default_permissions() {
  $permissions = array();

  // Exported permission: use vote up/down.
  $permissions['use vote up/down'] = array(
    'name' => 'use vote up/down',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'vud',
  );

  return $permissions;
}
