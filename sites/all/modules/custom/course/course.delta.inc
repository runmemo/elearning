<?php
/**
 * @file
 * course.delta.inc
 */

/**
 * Implements hook_delta_default_templates().
 */
function course_delta_default_templates() {
  $current_theme = theming_get_current_theme();
 
  $export = array();

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'course_pages';
  $delta->name = 'Course Pages';
  $delta->description = 'Delta for questions and blogs';
  $delta->theme = $current_theme; ;
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_' . $current_theme . '_settings' => array(
      'alpha_region_sidebar_second_zone' => NULL,
      'alpha_region_sidebar_second_equal_height_element' => FALSE,
      'alpha_region_content_columns' => '12',
    ),
  );
  $export['course_pages'] = $delta;

  return $export;
}
