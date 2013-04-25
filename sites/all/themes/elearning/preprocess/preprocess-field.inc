<?php
/**
 * Implements hook preprocess_field
 * 
 * redirects preprocessing to function constracted from bundle and field names.
 * @see elearning_preprocess_field__lesson_field_video
 * @param type $vars
 */
function elearning_alpha_preprocess_field(&$vars) {
  $function = __FUNCTION__ . '__' . $vars['element']['#bundle'] . '_' . $vars['element']['#field_name'];
  if(function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocessing of field_video on lesson node.
 */
function elearning_alpha_preprocess_field__lesson_field_video(&$vars) {
  $vars['classes_array'][] = 'grid-12';
  $vars['classes_array'][] = 'alpha';
  $vars['classes_array'][] = 'omega';
}

/**
 * Preprocessing of field_video on course node.
 */
function elearning_alpha_preprocess_field__course_field_video(&$vars) {
  $vars['classes_array'][] = 'grid-8';
  $vars['classes_array'][] = 'alpha';
  $vars['classes_array'][] = 'omega';
}
