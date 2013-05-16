<?php

/**
 * @file
 * abuse_content.features.inc
 */


/**
 * Implements hook_flag_default_flags().
 */
function abuse_content_flag_default_flags() {
  $flags = array();
  // Exported flag: "Abuse content".
  $flags['abuse_content'] = array(
    'entity_type' => 'node',
    'title' => t('Abuse content'),
    'global' => 0,
    'types' => array(
      0 => 'open_question_feedback',
    ),
    'flag_short' => t('Submit'),
    'flag_long' => t('Flag this content'),
    'flag_message' => '',
    'unflag_short' => t('Unflag this item'),
    'unflag_long' => t('Unflag this content'),
    'unflag_message' => '',
    'unflag_denied_text' => t('Unflag not allowed'),
    'link_type' => 'confirm',
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => 'others',
    'show_contextual_link' => 0,
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'i18n' => 0,
    'flag_confirmation' => t('Flag this content'),
    'unflag_confirmation' => t('Unflag this content'),
    'module' => 'course',
    'api_version' => 3,
  );

  return $flags;
}
