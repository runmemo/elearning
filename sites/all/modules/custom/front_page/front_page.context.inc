<?php
/**
 * @file
 * front_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function front_page_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front_page_context';
  $context->description = 'Context for front page of the website';
  $context->tag = 'Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-front_page_slider-block' => array(
          'module' => 'views',
          'delta' => 'front_page_slider-block',
          'region' => 'content',
          'weight' => '-30',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'home_page',
    ),
  );
  $context->condition_mode = 0;
  $export['front_page_context'] = $context;
  
  return $export;
}
