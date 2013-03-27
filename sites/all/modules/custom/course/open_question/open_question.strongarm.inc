<?php
/**
 * @file
 * open_question_strongarm.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function open_question_strongarm_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_open_question';
  $strongarm->value = 0;
  $export['comment_anonymous_open_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_open_question_answer';
  $strongarm->value = 0;
  $export['comment_anonymous_open_question_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_open_question';
  $strongarm->value = 1;
  $export['comment_default_mode_open_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_open_question';
  $strongarm->value = 1;
  $export['comment_subject_field_open_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_open_question_answer';
  $strongarm->value = 0;
  $export['comment_subject_field_open_question_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_open_question';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_open_question'] = $strongarm;

  return $export;
}
