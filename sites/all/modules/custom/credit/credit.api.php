<?php

/**
 * Defines credit information provided by modules for bundles
 *  - bundle: name of the content type that credit is calculated for
 *  - callback: function that calculates credit has 2 paramenters - $node, $account
 * 
 * @return array
 */
function hook_credit_info() {
  $results = array();
  $results['foo_bundle'] = array (
    'bundle' => 'foo',
    // callback function must return value between 0 and 1.
    'callback' => 'foo_result_calculate',
    
  );
  return $results;
}