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

  // Exported permission: subscribe to questions.
  $permissions['subscribe to questions'] = array(
    'name' => 'subscribe to questions',
    'roles' => array(),
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

  return $permissions;
}
