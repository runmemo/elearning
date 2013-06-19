<?php


/**
 * Implements hook_flag_default_flags().
 */
function newsfeed_flag_default_flags() {
  $flags = array();
  // Exported flag: "Follow content".
  $flags['follow_content'] = array(
    'entity_type' => 'node',
    'title' => 'Follow content',
    'global' => 0,
    'types' => array(),
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
    'import_roles' => array(
      'flag' => array(
        0 => 2,
    ),
      'unflag' => array(
        0 => 2,
      ),
    ),
  );
  // Exported flag: "Mark message as read".
  $flags['message_read'] = array(
    'entity_type' => 'message',
    'title' => 'Mark message as read',
    'global' => 0,
    'types' => array(),
    'errors' => array(),
    'flag_short' => t('Mark as read'),
    'flag_long' => t('Mark as read'),
    'flag_message' => '',
    'unflag_short' => t('Unflag this item'),
    'unflag_long' => t('Unflag this item'),
    'unflag_message' => '',
    'unflag_denied_text' => t('Marked as read'),
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'message_notify_email_subject' => 0,
      'message_notify_email_body' => 0,
      'message_notify_internal_body' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'api_version' => 3,
    'module' => 'newsfeed',
    'locked' => array(
      0 => 'name',
    ),
    'import_roles' => array(
      'flag' => array(
        0 => 2,
      )
    ),
  );
  return $flags;
}
