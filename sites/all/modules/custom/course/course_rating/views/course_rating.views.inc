<?php

/**
 * @file
 * course_rating.views.inc
 */

/**
 * Implements hook_views_data().
 */
function course_rating_views_data() {
  $data = array();
  $data['views']['course_rating_entity'] = array(
    'title' => t('Course Rating Entity'),
    'help' => t('Field for displaying review.'),
    'field' => array(
      'handler' => 'course_handler_field_course_rating_entity',
    ),
  );

  return $data;
}
