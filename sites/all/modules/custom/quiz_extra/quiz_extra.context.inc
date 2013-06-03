<?php
/**
 * @file
 * quiz_extra.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function quiz_extra_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'quiz';
  $context->description = '';
  $context->tag = 'Node';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*/take' => 'node/*/take',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'course_outline-course_outline' => array(
          'module' => 'course_outline',
          'delta' => 'course_outline',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'course_outline-course_certificate' => array(
          'module' => 'course_outline',
          'delta' => 'course_certificate',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node');
  $export['quiz'] = $context;

  return $export;
}
