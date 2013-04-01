<?php

/**
 * Implements hook_node_info().
 */
function lesson_node_info() {
  $items = array(
    'lesson' => array(
      'name' => t('Lesson'),
      'base' => 'node_content',
      'description' => 'Lesson with educational materials',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'notes' => array(
      'name' => t('Notes'),
      'base' => 'node_content',
      'description' => t('Student notes on lessons.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function lesson_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
