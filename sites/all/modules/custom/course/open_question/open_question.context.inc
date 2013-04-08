<?php
/**
 * @file
 * open_question.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function open_question_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'open_question';
  $context->description = 'Open Question';
  $context->tag = 'Node';
  $context->conditions = array(
    'course_access' => array(
      'values' => array(
        'true' => 'true',
      ),
    ),
    'node' => array(
      'values' => array(
        'open_question' => 'open_question',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'quicktabs-open_question_tabs' => array(
          'module' => 'quicktabs',
          'delta' => 'open_question_tabs',
          'region' => 'content',
          'weight' => '-10',
        ),
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Open Question');
  $export['open_question'] = $context;

  return $export;
}
