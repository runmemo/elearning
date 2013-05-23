<?php
/**
 * @file
 * user_extra.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function user_extra_user_default_roles() {
  $roles = array();

  // Exported role: pre-authorized.
  $roles['not-validated'] = array(
    'name' => 'not-validated',
    'weight' => 5,
  );

  return $roles;
}
