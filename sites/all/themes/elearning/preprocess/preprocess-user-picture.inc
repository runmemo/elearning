<?php

/**
 * Implements hook_preprocess_user_picture
 */
function elearning_alpha_preprocess_user_picture(&$vars) {
  if (empty($vars['size'])) {
    $vars['size'] = 'default';
  }
  if (empty($vars['userpoints'])) {
    $vars['userpoints'] = 0;
  }
}

