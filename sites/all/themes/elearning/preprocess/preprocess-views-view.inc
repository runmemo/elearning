<?php


/**
 * Preprocess for views view.
 * @param array $vars
 */
function elearning_alpha_preprocess_views_view(&$vars) {
  if (isset($vars['view']->name)) {
    $function = __FUNCTION__ . '__' . $vars['view']->name;
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Preprocess for "course_students" view.
 */
function elearning_alpha_preprocess_views_view__course_students(&$vars) {
  $vars['classes_array'][] = 'omega';
}

/**
 * Preprocess for "user_courses" view.
 */
function elearning_alpha_preprocess_views_view__user_courses(&$vars) {
  $vars['classes_array'][] = 'grid-9';
  $vars['classes_array'][] = 'omega';
}

/**
 * Preprocess for user_questions_list view.
 */
function elearning_alpha_preprocess_views_view__user_questions_list(&$vars) {
  $vars['classes_array'][] = 'view-questions-list';
}

/**
 * Preprocess for user_questions_list view.
 */
function elearning_alpha_preprocess_views_view__relevant_questions_list(&$vars) {
  $vars['classes_array'][] = 'view-questions-list';
}
