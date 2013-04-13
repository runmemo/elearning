<?php
/**
 * @file
 * best_answer_extra.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function best_answer_extra_flag_default_flags() {
  $flags = array();
  
  // Exported flag: "Flag for selecting best answer to the question".
  $flags['best_answer'] = array(
    'content_type' => 'node',
    'title' => 'Flag for selecting best answer to the question',
    'global' => 0,
    'types' => array(
      0 => 'answer',
    ),
    'flag_short' => 'Select',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unselect',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => 2,
      ),
      'unflag' => array(
        0 => 2,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'best_answer_extra',
    'locked' => array(
      0 => 'name',
    ),
  );
  
  return $flags;
}
