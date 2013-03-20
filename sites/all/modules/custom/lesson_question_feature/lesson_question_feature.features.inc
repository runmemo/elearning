<?php
/**
 * @file
 * lesson_question_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function lesson_question_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function lesson_question_feature_views_api() {
  return array("api" => "3.0");
}
