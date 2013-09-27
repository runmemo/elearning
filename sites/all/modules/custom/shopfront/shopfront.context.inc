<?php

/**
 * @file
 * product.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function shopfront_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'product_features_page';
  $context->description = 'Page that lists product details and features';
  $context->tag = 'Shopfront';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'product-details' => 'product-details',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'quicktabs-shopfront_product' => array(
          'module' => 'quicktabs',
          'delta' => 'shopfront_product',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'shopfront-shopfront_page_title' => array(
          'module' => 'shopfront',
          'delta' => 'shopfront_page_title',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
      ),
    ),
    'delta' => array(
      'delta_template' => 'shopfront_product_page',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basic page node is being viewed');
  $export['product_features_page'] = $context;

  return $export;
}
