<?php
/**
 * @file
 * shopfornt.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function shopfront_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'shopfront_product';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Shopfront product details';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'shopfront_product_features',
      'display' => 'block',
      'args' => '',
      'title' => 'Features',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'ui_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Features');
  t('Overview');
  t('Product details');

  $export['shopfront_product'] = $quicktabs;

  return $export;
}
