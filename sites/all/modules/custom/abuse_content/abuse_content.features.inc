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
  // @todo barinder add t() to text values bellow
  // Exported flag: "Abuse content".
  $flags['abuse_content'] = array(
    'entity_type' => 'node',
    'title' => 'Abuse content',
    'global' => 0,
    'types' => array(
      0 => 'open_question_feedback',
    ),
    'flag_short' => 'Submit',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag this item',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Unflag not allowed',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => 'others',
    'show_contextual_link' => 0,
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'i18n' => 0,
    'flag_confirmation' => 'Flag this content',
    'unflag_confirmation' => 'Unflag this content',
    'module' => 'course',
    'api_version' => 3,
  );

  return $flags;
}
