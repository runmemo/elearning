<?php

/**
 * Implements hook_preprocess_user_picture
 */
function elearning_alpha_preprocess_user_picture(&$vars) {
  if (!isset($vars['size'])) {
    $vars['size'] = 'default';
  }
}

