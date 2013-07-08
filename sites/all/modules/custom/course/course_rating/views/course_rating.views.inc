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
  $data['views']['course_rating'] = array(
    'title' => t('Course Rating'),
    'help' => t('Field for displaying average course rating.'),
    'field' => array(
      'handler' => 'course_rating_handler_field_course_rating',
    ),
  );

  return $data;
}
