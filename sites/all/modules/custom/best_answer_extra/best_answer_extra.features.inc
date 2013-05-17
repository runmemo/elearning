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
    'entity_type' => 'node',
    'title' => t('Flag for selecting best answer to the question'),
    'global' => 0,
    'types' => array(
      0 => 'answer',
    ),
    'flag_short' => t('Select'),
    'flag_long' => t('Select this question as best'),
    'flag_message' => '',
    'unflag_short' => t('Unselect'),
    'unflag_long' => t('Unselect best answer'),
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'i18n' => 0,
    'module' => 'best_answer_extra',
    'api_version' => 3,
  );
 
  return $flags;
}
