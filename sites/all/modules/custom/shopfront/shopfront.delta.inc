<?php
/**
 * @file
 * product.delta.inc
 */

/**
 * Implements hook_delta_default_templates().
 */
function shopfront_delta_default_templates() {
  $export = array();

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'shopfront_product_page';
  $delta->name = 'Product details';
  $delta->description = 'Delta for shopfront product page';
  $delta->theme = 'product';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_product_settings' => array(
      'alpha_exclude' => array(
        'modules/system/system.menus.css' => 'modules/system/system.menus.css',
        'modules/system/system.theme.css' => 'modules/system/system.theme.css',
      ),
      'alpha_region_sidebar_second_zone' => NULL,
      'alpha_region_sidebar_second_equal_height_element' => FALSE,
      'alpha_region_sidebar_first_columns' => '12',
      'alpha_region_content_columns' => '4',
    ),
  );
  $export['shopfront_product_page'] = $delta;

  return $export;
}
