<?php
/**
 * @file
 * lesson_question_feature.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function lesson_questions_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'lesson_interaction';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Lesson interaction';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'lesson_questions_delta_lesson_questions',
      'hide_title' => 1,
      'title' => 'Questions',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'search_delta_form',
      'hide_title' => 1,
      'title' => 'Search',
      'weight' => '-99',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'ui_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 0,
  );
  $export['lesson_interaction'] = $quicktabs;

  return $export;
}
