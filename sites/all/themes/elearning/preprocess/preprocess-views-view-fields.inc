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
 *  Implements hook_preprocess_views_view_fields 
 *  for relevant_questions_list view.
 *  
 *  @see elearning_alpha_preprocess_views_view_fields
 */
function elearning_alpha_preprocess_views_view_fields__relevant_questions_list(&$vars) {
 
  if (isset($vars['fields']['field_answer_count'])) {
    // Here we preprocess field that shows number of answers
    $answers_count_field = $vars['fields']['field_answer_count'];
    // Get origitnal field value. @todo get value instead of content.
    $answers = $answers_count_field->content;
    $output = 
    '<div class="left">
      <div class="answer-count">' .
        $answers .
      '<div class="title">' . format_plural($answers, 'Answer', 'Answers') . 
       '</div>
     </div>
    </div>';
    // Replace content of the field.
    $answers_count_field->content = $output;
  }  
}