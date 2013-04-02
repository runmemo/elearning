<?php

/**
 * @file
 * class_context_delta.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function class_context_delta_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'class';
  $context->description = '';
  $context->tag = 'theme class';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'closedquestion' => 'closedquestion',
        'lesson' => 'lesson',
        'open_question' => 'open_question',
        'quiz' => 'quiz',
      ),
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
          'region' => 'preface_first',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'class',
    ),
  );
  $context->condition_mode = 0;
  
  $export['class'] = $context;
  // Translatables
  // Included for use with string extractors like potx.
  t('theme class');

  
  return $export;
}
