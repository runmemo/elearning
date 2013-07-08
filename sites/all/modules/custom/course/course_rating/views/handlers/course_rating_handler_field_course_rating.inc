<?php

/**
 * @file
 * Definition of course_handler_field_course_rating.
 */

/**
 * Render rating field as the average rating of the course.
 *
 * @ingroup views_field_handlers
 */
class course_handler_field_course_rating extends views_handler_field {

  function query($group_by = FALSE) {
    // No query.
  }

  function render($values) {
    $rating = 0;
    if (isset($values->nid)) {
      $rating = course_get_course_rating($values->nid);
    }

    return theme('fivestar_static', array('rating' => $rating));
  }

}
