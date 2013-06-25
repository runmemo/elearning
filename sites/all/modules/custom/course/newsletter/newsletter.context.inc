<?php
/**
 * @file
 * newsletter.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function newsletter_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'annoucement_page';
  $context->description = '';
  $context->tag = 'Node';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'newsletter' => 'newsletter',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'course-book_header' => array(
          'module' => 'course',
          'delta' => 'book_header',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'relevant_answers_extra-relevant_questions_list' => array(
          'module' => 'relevant_answers_extra',
          'delta' => 'relevant_questions_list',
          'region' => 'postscript_first',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'newsletter_node',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node');
  $export['annoucement_page'] = $context;

  return $export;
}
