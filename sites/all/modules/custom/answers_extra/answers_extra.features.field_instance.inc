<?php
/**
 * @file
 * answers_extra.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function answers_extra_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-answer-field_answer_rating'
  $field_instances['node-answer-field_answer_rating'] = array(
    'bundle' => 'answer',
    'default_value' => array(
      0 => array(
        'vud_widget' => 'updown',
        'votingapi_tag' => 'vote',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'vud_field',
        'settings' => array(),
        'type' => 'default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_answer_rating',
    'label' => 'Answer rating widget',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'votingapi_tag' => 'vote',
      'vud_widget' => 'updown',
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'vud_field',
      'settings' => array(),
      'type' => 'vud_field_default_widget',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-question-field_answer_rating'
  $field_instances['node-question-field_answer_rating'] = array(
    'bundle' => 'question',
    'default_value' => array(
      0 => array(
        'vud_widget' => 'updown',
        'votingapi_tag' => 'vote',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'vud_field',
        'settings' => array(),
        'type' => 'default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_answer_rating',
    'label' => 'Question rating widget',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'votingapi_tag' => 'vote',
      'vud_widget' => 'answers',
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'vud_field',
      'settings' => array(),
      'type' => 'vud_field_default_widget',
      'weight' => 2,
    ),
  );

    // Exported field_instance: 'message-question_answer_notification-field_message_answer'
  $field_instances['message-question_answer_notification-field_message_answer'] = array(
    'bundle' => 'question_answer_notification',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'message_notify_email_body' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'message_notify_email_subject' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'message_notify_internal_body' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'field_message_answer',
    'label' => 'Message Answer',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'message-question_answer_notification-field_message_question'
  $field_instances['message-question_answer_notification-field_message_question'] = array(
    'bundle' => 'question_answer_notification',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'message_notify_email_body' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'message_notify_email_subject' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'message_notify_internal_body' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'field_message_question',
    'label' => 'Message Question',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  
  // Translatables
  // Included for use with string extractors like potx.
  t('Answer rating widget');
  t('Question rating widget');
  t('Message Answer');
  t('Message Question');
  return $field_instances;
}
