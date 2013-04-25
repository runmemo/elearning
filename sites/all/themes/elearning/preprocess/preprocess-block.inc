<?php

/**
 * Implements hook_preprocess_block
 * Function redirects processing to functions that are buld of hook plus block id.
 * @see elearning_alpha_preprocess_block__answers_extra_question_answers
 */
function elearning_alpha_preprocess_block(&$vars) {
  if (isset($vars['elements'])) {
    $function = __FUNCTION__ . '__' . $vars['elements']['#block']->module . '_' . $vars['elements']['#block']->delta;
    // uncomment line bellow if you want to see the full id of needed block:
    // dvm ($vars['elements']['#block']->module . '_' . $vars['elements']['#block']->delta);
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Preprocessing for block Lesson Questions / Lesson Question Answers
 */
function elearning_alpha_preprocess_block__answers_extra_question_answers(&$vars) {
   $vars['attributes_array']['class'][] = 'grid-11 alpha omega';
}

