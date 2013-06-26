<?php
/**
 * @file
 * config.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function config_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'header_footer';
  $context->description = 'Header and footer blocks';
  $context->tag = 'Page';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'superfish-1' => array(
          'module' => 'superfish',
          'delta' => '1',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'superfish-2' => array(
          'module' => 'superfish',
          'delta' => '2',
          'region' => 'branding',
          'weight' => '-9',
        ),
        'newsfeed-user_notifications_count' => array(
          'module' => 'newsfeed',
          'delta' => 'user_notifications_count',
          'region' => 'branding',
          'weight' => '-8',
        ),
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'config-rights_reserved' => array(
          'module' => 'config',
          'delta' => 'rights_reserved',
          'region' => 'footer_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Header and footer blocks');
  t('Page');
  $export['header_footer'] = $context;

  return $export;
}
