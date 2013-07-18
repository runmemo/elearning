<?php
/**
 * @file
 * classroom.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function classroom_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function classroom_node_info() {
  $items = array(
    'course_group' => array(
      'name' => t('Course Group'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
