<?php
/**
 * @file
 * course_rating.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function course_rating_field_default_field_instances() {
  $field_instances = array();

  // @todo Ilya create field base for field_rating in this module.
  
  // Exported field_instance: 'node-course-field_rating'
  $field_instances['node-course-field_rating'] = array(
    'bundle' => 'course',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => 1,
          'style' => 'user',
          'text' => 'none',
          'widget' => array(
            'fivestar_widget' => 'default',
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_rating',
    'label' => 'Rate the usefulness of the course on a scale',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'stars' => 10,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(),
      'type' => 'exposed',
      'weight' => 32,
    ),
  );
  
  // Translatables
  // Included for use with string extractors like potx.
  t('Course');
  t('Rating');

  return $field_instances;
}
