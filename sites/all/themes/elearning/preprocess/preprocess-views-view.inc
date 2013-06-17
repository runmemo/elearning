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
 * Preprocess for course_students view.
 */
function elearning_alpha_preprocess_views_view__course_students(&$vars) {
  $vars['classes_array'][] = 'omega';
}

/**
 * Preprocess for user_questions_list view.
 */
function elearning_alpha_preprocess_views_view__user_questions_list(&$vars) {
  $vars['classes_array'][] = 'view-questions-list';
}

/**
 * Preprocess for relevant_questions_list view.
 */
function elearning_alpha_preprocess_views_view__relevant_questions_list(&$vars) {
  $vars['classes_array'][] = 'view-questions-list';
}

/**
 * Preprocess for user_questions_list view.
 */
function elearning_alpha_preprocess_views_view__user_answers_list(&$vars) {
  $vars['classes_array'][] = 'view-user-answers-list';
}

/**
 * Preprocess for user_questions_list view.
 */
function elearning_alpha_preprocess_views_view__user_courses(&$vars) {
  
  // Get user for current profile page.
  $account = menu_get_object('user');
  if (!$account) {
    return;
  }
  // Get current user.
  global $user;
  // Here we check if user is looking at his account 
  // and set view header accordingly.
  if ($user->uid === $account->uid) {
    $header = t('My courses');
  } else {
    $account_wrapper = entity_metadata_wrapper('user', $account);
    $name = $account_wrapper->field_first_name->value();
    $header =  t('@name attends courses', array('@name' => $name));
  }
  // Wrap header for styling pursposes.
  $vars['header'] = '<p>' . $header . '</p>';
}
