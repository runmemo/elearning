<?php
/**
 * @file
 * subscriptions_question.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function subscriptions_question_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function subscriptions_question_flag_default_flags() {
  $flags = array();
  // Exported flag: "follow question".
  $flags['follow_question'] = array(
    'entity_type' => 'node',
    'title' => 'follow question',
    'global' => 0,
    'types' => array(
      0 => 'question',
    ),
    'flag_short' => 'Follow',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unfollow',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'test',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;
}
