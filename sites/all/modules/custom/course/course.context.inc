<?php

/**
 * @file
 * lesson.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function course_context_default_contexts() {
  $export = array();
  
  // build array of bundles that can be course items
  $node_values = array();
  $course_bundles = course_item_node_types();
  foreach ($course_bundles as $bundle) {
    $node_values[$bundle] = $bundle;
  }
 
  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'course_item';
  $context->description = 'Node is part of the course';
  $context->tag = 'Node';
  $context->conditions = array(
    'course_access' => array( // this means that 
      'values' => array(
        'true' => 'true',
      ),
    ),
    'node' => array(
      'values' => $node_values,
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'course_outline-book_outline' => array(
          'module' => 'course_outline',
          'delta' => 'book_outline',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['course_item'] = $context;


  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'teacher_course_items';
  $context->description = 'When teacher is viewing course item';
  $context->tag = 'Node';
  $context->conditions = array(
    'node' => array(
      'values' => $node_values,
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'teacher' => 'teacher',
      ),
    ),
    'path' => array(
      'values' => array(
        'node/*/outline' => 'node/*/outline',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'course-course_item_links' => array(
          'module' => 'course',
          'delta' => 'course_item_links',
          'region' => 'content',
          'weight' => '-33',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['teacher_course_items'] = $context;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node');
  t('When teacher is viewing course item');

  return $export;
}
