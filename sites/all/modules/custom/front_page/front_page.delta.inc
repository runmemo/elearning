<?php
/**
 * @file
 * front_page.delta.inc
 */

/**
 * Implements hook_delta_default_templates().
 */
function front_page_delta_default_templates() {
  $export = array();

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'home_page';
  $delta->name = 'Home page';
  $delta->description = 'Delta for home page';
  $delta->theme = 'elearning';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_elearning_settings' => array(
      'alpha_layouts_alpha_default_narrow_responsive' => 0,
      'alpha_layouts_alpha_default_wide_responsive' => 0,
      'alpha_css' => array(
        'alpha-reset.css' => 'alpha-reset.css',
        'alpha-mobile.css' => 'alpha-mobile.css',
        'alpha-alpha.css' => 'alpha-alpha.css',
        'omega-text.css' => 'omega-text.css',
        'omega-branding.css' => 'omega-branding.css',
        'omega-menu.css' => 'omega-menu.css',
        'omega-forms.css' => 'omega-forms.css',
        'omega-visuals.css' => 'omega-visuals.css',
        'global.css.less' => 'global.css.less',
        'elearning-alpha-default-normal.css' => 'elearning-alpha-default-normal.css',
        'elearning-alpha-default-wide.css' => 0,
        'elearning-alpha-default-narrow.css' => 0,
      ),
    ),
  );
  $export['home_page'] = $delta;

  return $export;
}
