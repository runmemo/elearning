<?php

/**
 * @file
 * course_rating.pages.inc
 */

/**
 * Page callback for displaying rating form.
 * 
 * @param object $course
 *   Course node object
 * @param type $user
 *   User object
 * 
 * @return string
 *   HTML output
 */
function course_rating_page($course, $user) {
  if (!course_registration_id($user->uid, $course->nid)) {
    return t('Please, register to the !course.', array('!course' => l(t('course'), 'course/' . $course->nid)));
  }
  if (!isset($_SESSION['courses_rating']['course_' . $course->nid]['rating_nid'])) {
    $_SESSION['courses_rating']['course_' . $course->nid]['rating_nid'] = course_is_reviewed($course->nid, $user->uid);
  }
  $field = field_view_field('node', $course, 'field_rating');
  $field['#pre_render'] = array('course_rating_pre_render_fivestar');

  return render($field);
}
