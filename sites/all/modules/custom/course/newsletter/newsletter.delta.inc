<?php
/**
 * @file
 * newsletter.delta.inc
 */

/**
 * Implements hook_delta_default_templates().
 */
function newsletter_delta_default_templates() {
  $current_theme = theming_get_current_theme();

  $export = array();

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'newsletter_node';
  $delta->name = 'Newsletter node';
  $delta->description = '';
  $delta->theme = $current_theme;
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_' . $current_theme . '_settings' => array(
      'alpha_region_sidebar_first_zone' => NULL,
      'alpha_region_content_columns' => '14',
      'alpha_region_content_suffix' => '2',
      'alpha_region_sidebar_second_zone' => NULL,
      'alpha_region_postscript_first_prefix' => '2',
      'alpha_region_postscript_first_columns' => '12',
      'alpha_region_postscript_first_suffix' => '2',
      'alpha_region_postscript_second_zone' => NULL,
      'alpha_region_postscript_third_zone' => NULL,
      'alpha_region_postscript_fourth_zone' => NULL,
    ),
  );
  $export['newsletter_node'] = $delta;

  return $export;
}
