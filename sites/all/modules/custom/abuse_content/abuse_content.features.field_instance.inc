<?php
/**
 * @file
 * abuse_content.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function abuse_content_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'flagging-abuse_content-field_abuse_description'
  $field_instances['flagging-abuse_content-field_abuse_description'] = array(
    'bundle' => 'abuse_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'flagging',
    'field_name' => 'field_abuse_description',
    'label' => 'Abuse Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'flagging-abuse_content-field_abuse_reason'
  $field_instances['flagging-abuse_content-field_abuse_reason'] = array(
    'bundle' => 'abuse_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'flagging',
    'field_name' => 'field_abuse_reason',
    'label' => 'Abuse reason',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Abuse Description');
  t('Abuse reason');

  return $field_instances;
}
