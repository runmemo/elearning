<?php
/**
 * @file
 * lesson.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function lesson_strongarm() {
  $export = array();

  // Provides default url alias for Question nodes.
  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_answer_pattern';
  $strongarm->value = 'question/[node:nid]';
  $export['pathauto_node_question_pattern'] = $strongarm;
  
  return $export;
}
