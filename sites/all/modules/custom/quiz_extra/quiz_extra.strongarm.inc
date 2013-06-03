<?php
/**
 * @file
 * test.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function test_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_quiz';
  $strongarm->value = 0;
  $export['node_submitted_quiz'] = $strongarm;

  return $export;
}
