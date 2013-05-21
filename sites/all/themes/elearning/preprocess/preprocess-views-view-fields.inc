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

/**
 *  Implements hook_preprocess_views_view_fields for user_answers_list view.
 *  
 *  @see elearning_alpha_preprocess_views_view_fields
 */
function elearning_alpha_preprocess_views_view_fields__user_answers_list(&$vars) {
  if (isset($vars['fields']['field_answer_question'])) {
    $vars['fields']['field_answer_question']->wrapper_prefix = '<div class="field-answer-question">';
    $vars['fields']['field_answer_question']->wrapper_suffix  = '</div>';
  }  
}
