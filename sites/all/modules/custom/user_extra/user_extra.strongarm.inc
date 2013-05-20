<?php
/**
 * @file
 * user_extra.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function user_extra_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_medium_dot';
  $strongarm->value = 'd.m.Y - H:i';
  $export['date_format_medium_dot'] = $strongarm;

  return $export;
}
