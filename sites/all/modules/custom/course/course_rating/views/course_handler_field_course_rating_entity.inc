<?php

/**
 * @file
 * Definition of course_handler_field_course_rating_entity.
 */

/**
 * Field, displaying review of the Course Rating entity.
 *
 * @ingroup views_field_handlers
 */
class course_handler_field_course_rating_entity extends views_handler_field {

  function query($group_by = FALSE) {
    // No query.
  }

  function render($values) {
    $review = '';
    if (isset($values->nid) && isset($values->users_votingapi_vote_uid)) {
      $rating_id = course_rating_reviewed($values->nid, $values->users_votingapi_vote_uid);
      if ($rating_id) {
        $course_rating = course_rating_load($rating_id);
        $review = $course_rating->review;
      }
    }

    return $review;
  }

}
