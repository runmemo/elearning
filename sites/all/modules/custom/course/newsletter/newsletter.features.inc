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

/**
 * Implements hook_flag_default_flags().
 */
function newsletter_flag_default_flags() {
  $flags = array();
  // Exported flag: "Follow Course Blog".
  $flags['subscriptions_course_blog'] = array(
    'entity_type' => 'node',
    'title' => 'Follow Course Blog',
    'global' => 0,
    'types' => array(
      0 => 'course',
    ),
    'errors' => array(),
    'flag_short' => t('Follow'),
    'flag_long' => t('Follow'),
    'flag_message' => '',
    'unflag_short' => t('Unfollow'),
    'unflag_long' => t('Unfollow'),
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'print' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
  );
  
  return $flags;
}
