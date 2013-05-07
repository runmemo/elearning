<?php
/**
 * @file
 * subscriptions_question.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function subscriptions_question_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer user subscriptions.
  $permissions['administer user subscriptions'] = array(
    'name' => 'administer user subscriptions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: bulk-administer user subscriptions.
  $permissions['bulk-administer user subscriptions'] = array(
    'name' => 'bulk-administer user subscriptions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: flag follow_question.
  $permissions['flag follow_question'] = array(
    'name' => 'flag follow_question',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: subscribe to all content types.
  $permissions['subscribe to all content types'] = array(
    'name' => 'subscribe to all content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: subscribe to content.
  $permissions['subscribe to content'] = array(
    'name' => 'subscribe to content',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: subscribe to content types.
  $permissions['subscribe to content types'] = array(
    'name' => 'subscribe to content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: subscribe to referenced node.
  $permissions['subscribe to referenced node'] = array(
    'name' => 'subscribe to referenced node',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: suspend own subscriptions.
  $permissions['suspend own subscriptions'] = array(
    'name' => 'suspend own subscriptions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: unflag follow_question.
  $permissions['unflag follow_question'] = array(
    'name' => 'unflag follow_question',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
