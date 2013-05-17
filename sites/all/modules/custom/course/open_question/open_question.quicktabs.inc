<?php
/**
 * @file
 * open_question.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function open_question_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'open_question_tabs';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Open Question Tabs';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'open_question_delta_oq_answer_form_block',
      'hide_title' => 1,
      'title' => t('My answer'),
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'open_question_delta_oq_other_answers_block',
      'hide_title' => 1,
      'title' => t('Review answers'),
      'weight' => '-99',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'ui_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('My Answer');
  t('Open Question Tabs');
  t('Review Answers');

  $export['open_question_tabs'] = $quicktabs;

  return $export;
}
