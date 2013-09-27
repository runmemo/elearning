<?php
/**
 * @file
 * product_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function shopfront_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function shopfront_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}


/**
 * Implements hook_node_info().
 */
function shopfront_node_info() {
  $items = array(
    'product_feature' => array(
      'name' => t('Product Feature'),
      'base' => 'node_content',
      'description' => t('Coursehub product feature.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  
  $items = array(
    'document' => array(
      'name' => t('Document'),
      'base' => 'node_content',
      'description' => t('Contains documents that can be uploaded'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  
  return $items;
}
