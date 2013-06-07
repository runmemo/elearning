<?php
/**
 * @file
 * newsfeed.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function newsfeed_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__question_answer_notification';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_internal_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_internal_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__question_answer_notification'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_subscribe_default_notifiers';
  $strongarm->value = array(
    'internal' => 'internal',
  );
  $export['message_subscribe_default_notifiers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_subscribe_flag_prefix';
  $strongarm->value = 'subscriptions';
  $export['message_subscribe_flag_prefix'] = $strongarm;

  return $export;
}