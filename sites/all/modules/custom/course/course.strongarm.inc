<?php
/**
 * @file
 * course.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function course_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_lesson';
  $strongarm->value = 0;
  $export['node_submitted_lesson'] = $strongarm;

  // PathAuto pattern for Course content type.
  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_course_pattern';
  $strongarm->value = 'course/[node:nid]';
  $export['pathauto_node_course_pattern'] = $strongarm;

  
  return $export;
}
