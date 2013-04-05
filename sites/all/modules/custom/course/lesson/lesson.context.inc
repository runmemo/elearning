<?php
/**
 * @file
 * lesson.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function lesson_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'lesson';
  $context->description = 'Lesson Node';
  $context->tag = 'Node';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'lesson' => 'lesson',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'quicktabs-lesson_interaction' => array(
          'module' => 'quicktabs',
          'delta' => 'lesson_interaction',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Lesson Node');
  t('Node');
  $export['lesson'] = $context;

  return $export;
}
