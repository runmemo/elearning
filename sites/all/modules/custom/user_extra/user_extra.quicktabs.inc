<?php
/**
 * @file
 * user_extra.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function user_extra_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'user_profile_tab';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'User Profile Tab';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'views_delta_user_questions_list-block',
      'hide_title' => 1,
      'title' => t('My questions'),
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'views_delta_user_answers_list-block',
      'hide_title' => 1,
      'title' => t('Answers'),
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'user_extra_delta_user_extra_userpoints_block',
      'hide_title' => 1,
      'title' => t('History'),
      'weight' => '-98',
      'type' => 'block',
    ),
    3 => array(
      'bid' => 'views_delta_courses_reviews-block',
      'hide_title' => 1,
      'title' => t('Reviews'),
      'weight' => '-97',
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
  t('History');
  t('Answers');
  t('Questions');
  t('Reviews');
  t('User Profile Tab');

  $export['user_profile_tab'] = $quicktabs;

  return $export;
}
