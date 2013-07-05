<?php
/**
 * @file
 * course_access.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function course_access_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-course-field_stage'
  $field_instances['node-course-field_stage'] = array(
    'bundle' => 'course',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_stage',
    'label' => 'Stage',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Stage');

  return $field_instances;
}
