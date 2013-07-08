<?php
/**
 * @file
 * course_rating.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function course_rating_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function course_rating_views_api() {
  return array(
    'api' => '3.0', 
    'path' =>  drupal_get_path('module', 'course_rating') . '/views', 
  );
}

/**
 * Implements hook_node_info().
 */
function course_rating_node_info() {
  $items = array(
    'course_rating' => array(
      'name' => t('Course Rating'),
      'base' => 'node_content',
      'description' => t('Course rating content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
