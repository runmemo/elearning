<?php
/**
 * @file
 * class_context_delta.delta.inc
 */

/**
 * Implements hook_delta_default_templates().
 */
function class_context_delta_delta_default_templates() {
  $export = array();

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'class';
  $delta->name = 'Class';
  $delta->description = 'Layout for course classes';
  $delta->theme = 'elearning';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_elearning_settings' => array(
      'alpha_zone_content_columns' => '16',
      'alpha_region_sidebar_first_columns' => '4',
      'alpha_region_content_columns' => '12',
      'alpha_region_sidebar_second_zone' => NULL,
    ),
  );
  $export['class'] = $delta;

  return $export;
}
