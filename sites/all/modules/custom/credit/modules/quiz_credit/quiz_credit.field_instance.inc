<?php
/**
 * @file
 * field_pass_credit.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function quiz_credit_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-open_question-field_course_credit'
  $field_instances['node-quiz-field_course_credit'] = array(
    'bundle' => 'quiz',
    'entity_type' => 'node',
    'field_name' => 'field_course_credit',
    'label' => 'Course Credit',
    'required' => 0,
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
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
      'weight' => -1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Course Credit');

  return $field_instances;
}
