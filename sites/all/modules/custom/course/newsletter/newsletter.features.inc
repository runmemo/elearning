<?php
/**
 * @file
 * newsletter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function newsletter_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function newsletter_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function newsletter_node_info() {
  $items = array(
    'newsletter' => array(
      'name' => t('Newsletter'),
      'base' => 'node_content',
      'description' => t('Course Blog'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
