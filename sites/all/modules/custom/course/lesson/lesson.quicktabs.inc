<?php
/**
 * @file
 * lesson_question_feature.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function lesson_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'lesson_interaction';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Lesson interaction';
  if(module_exists('relevant_answers_extra')) {
    $quicktabs->tabs[0] = array(
        'bid' => 'relevant_answers_extra_delta_relevant_questions_list',
        'hide_title' => 1,
        'title' => 'Questions',
        'weight' => '0',
        'type' => 'block',
    );
  }
  $quicktabs->tabs[1]  = array(
      'bid' => 'lesson_delta_lesson_lecturer_notes',
      'hide_title' => 1,
      'title' => 'Notes',
      'weight' => '1',
      'type' => 'block',
  );
  
  $quicktabs->tabs[2] = array(
    'bid' => 'lesson_delta_lesson_student_notes',
    'hide_title' => 1,
    'title' => 'Student Notes',
    'weight' => '2',
    'type' => 'block',
  );
  $quicktabs->renderer = 'ui_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 0,
  );
  $export['lesson_interaction'] = $quicktabs;

  return $export;
}
