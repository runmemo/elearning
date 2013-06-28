<?php

/**
 * @file
 * course.views.inc
 */


/**
 * Implements hook_views_data().
 */
function course_views_data() {
  $data = array();
  $data['views']['course_rating'] = array(
    'title' => t('Course Rating'),
    'help' => t('Field for displaying average course rating.'),
    'field' => array(
      'handler' => 'course_handler_field_course_rating',
    ),
  );

  return $data;
}
