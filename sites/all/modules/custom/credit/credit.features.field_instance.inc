<?php
/**
 * @file
 * field_pass_credit.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function field_pass_credit_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-course-field_pass_credit'
  $field_instances['node-course-field_pass_credit'] = array(
    'bundle' => 'course',
    'default_value' => array(
      0 => array(
        'value' => 50,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pass_credit',
    'label' => 'Pass Credit',
    'required' => 1,
    'settings' => array(
      'max' => 100,
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Pass Credit');

  return $field_instances;
}
