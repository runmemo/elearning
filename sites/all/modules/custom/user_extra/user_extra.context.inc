<?php
/**
 * @file
 * user_extra.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function user_extra_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_profile';
  $context->description = 'user profile tabs';
  $context->tag = 'user';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'quicktabs-user_profile_tab' => array(
          'module' => 'quicktabs',
          'delta' => 'user_profile_tab',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('user');
  t('user profile tabs');
  $export['user_profile'] = $context;

  return $export;
}
