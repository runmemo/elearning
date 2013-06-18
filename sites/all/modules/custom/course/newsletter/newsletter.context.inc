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
        'views-237de9699f9cabc11c225b56215797a5' => array(
          'module' => 'views',
          'delta' => '237de9699f9cabc11c225b56215797a5',
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

  $export['annoucement_page'] = $context;
  
  return $export;
}
