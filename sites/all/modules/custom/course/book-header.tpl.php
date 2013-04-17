<?php
/**
 * @file
 * Theme implementation for course Header
 *
 * Presented above nodes that are a part of course outlines.
 *
 * Available variables:
 * - $course_title: Course Title
 * - $provider_logo: Logo of course provider
 * - $teacher_name: Name of teacher for course
 * - $teacher_surname: SurName of teacher for course
 * - $lesson_link: Lesson link for question page.
 *
 */
?>
<div class="book-header">
    <div class="provider-logo">
      <?php print render($provider_logo); ?>
    </div>  
   <div class="title-wrapper">
      <div class="course-title">
        <?php print $course_title; ?>
      </div>
      <div class="teacher-name">
        <?php print $teacher_name . '&nbsp;' . $teacher_surname; ?>
      </div>
  </div>
  <?php print $lesson_link; ?>
</div>
