<?php

/**
 * @file
 * registration.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function registration_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'no_registration_access';
  $context->description = 'User tries to open course item without registration';
  $context->tag = 'access';
  $context->conditions = array(
    'course_access' => array(
      'values' => array(
        'false' => 'false',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'course-registration_form' => array(
          'module' => 'course',
          'delta' => 'registration_form',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

// Translatables
// Included for use with string extractors like potx.
  t('User tries to open course item without registration');
  t('access');
 
  $export['non_registered'] = $context;
  return $export;
}
