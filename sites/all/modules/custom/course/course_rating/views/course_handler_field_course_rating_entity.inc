<?php

/**
 * @file
 * Definition of course_handler_field_course_rating_entity.
 */

/**
 * Filter to handle users, who voted for the course.
 *
 * @ingroup views_filter_handlers
 */
class course_handler_field_course_rating_entity extends views_handler_field {

  function query($group_by = FALSE) {
    // No query.
  }

  function render($values) {
    $review = 0;
    if (isset($values->nid) && isset($values->votingapi_vote_node_percent_vote_uid)) {
      $rating_id = course_rating_reviewed($values->nid, $values->votingapi_vote_node_percent_vote_uid);
      if ($rating_id) {
        $course_rating = course_rating_load($rating_id);
        $review = $course_rating->review;
      }
    }

    return $review;
  }

}
