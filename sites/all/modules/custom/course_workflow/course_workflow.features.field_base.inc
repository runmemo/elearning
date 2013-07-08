<?php
/**
 * @file
 * course_workflow.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function course_workflow_field_default_field_bases() {
  $field_bases = array();
  
  // Exported field_base: 'field_stage'
  $field_bases['field_stage'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_stage',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Submitted',
        2 => 'Published',
        3 => 'Archived',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
