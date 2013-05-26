<?php

/**
 * Implements hook_preprocess_user_picture
 */
function elearning_alpha_preprocess_user_picture(&$vars) {
  if (!isset($vars['size'])) {
    $vars['size'] = 'default';
  }
  if (isset($vars['show_points']) && $vars['show_points']) {
    $userpoints = userpoints_get_current_points($vars['account']->uid, 'all');
    $vars['userpoints'] = $userpoints;
  }
}

