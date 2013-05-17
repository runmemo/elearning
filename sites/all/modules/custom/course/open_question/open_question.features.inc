<?php

/**
 * @file
 * open_question.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function open_question_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function open_question_views_api() {
  return array(
    'api' => '3.0',
    'path' => drupal_get_path('module', 'open_question') . '/views', );
}

/**
 * Implements hook_flag_default_flags().
 */
function open_question_flag_default_flags() {
  $flags = array();
  // Exported flag: "Flag to mark feedback as useful".
  $flags['opaf_useful'] = array(
    'entity_type' => 'node',
    'title' => 'Flag to mark feedback as useful',
    'global' => 0,
    'types' => array(
      0 => 'open_question_feedback',
    ),
    'flag_short' => 'Select',
    'flag_long' => 'This feedback is useful',
    'flag_message' => '',
    'unflag_short' => 'Unselect',
    'unflag_long' => 'This feedback is not useful',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => 'others',
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'open_question',
    'locked' => array(
      'name' => 'name',
    ),
    'status' => FALSE,
    'import_roles' => array(
      'flag' => array(
        0 => 2,
      ),
      'unflag' => array(
        0 => 2,
      ),
    ),
  );
  return $flags;
}

/**
 * Implements hook_node_info().
 */
function open_question_node_info() {
  $items = array(
    'open_question' => array(
      'name' => t('Open Question'),
      'base' => 'node_content',
      'description' => t('Represents open questions that can be part of the course and can be answered by a student.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'open_question_answer' => array(
      'name' => t('Open Question Answer'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'open_question_feedback' => array(
      'name' => t('Open Question Feedback'),
      'base' => 'node_content',
      'description' => t('Feedback provided to the user by other students on the Open Questions page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_image_default_styles().
 */
function open_question_image_default_styles() {
  $styles = array();

  // Exported image style: question_author.
  $styles['question_author'] = array(
    'name' => 'question_author',
    'effects' => array(
      9 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '44',
          'height' => '44',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
