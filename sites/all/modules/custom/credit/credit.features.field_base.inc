<?php
/**
 * @file
 * credit2.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function credit_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_course_credit'
  $field_bases['field_course_credit'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_course_credit',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );
  
  // Exported field_base: 'field_pass_credit'
  $field_bases['field_pass_credit'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pass_credit',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
