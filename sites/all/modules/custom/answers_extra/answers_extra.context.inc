<?php
/**
 * @file
 * answers_extra.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function answers_extra_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'question';
  $context->description = 'Question node page context';
  $context->tag = 'Node';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'question' => 'question',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'answers_extra-question_answers' => array(
          'module' => 'answers_extra',
          'delta' => 'question_answers',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node');
  t('Question node page context');
  $export['question'] = $context;

  return $export;
}