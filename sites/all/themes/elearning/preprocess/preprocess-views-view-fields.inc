<?php

/**
 * Implements hook_preprocess_views_view_fields.
 */
function elearning_alpha_preprocess_views_view_fields(&$vars) {
  $view = $vars['view'];
  if (!isset($view->name)) {
    return;
  }
  $function = __FUNCTION__ . '__' . $view->name;
  if (function_exists($function)) {
    $function($vars);
  }
}
