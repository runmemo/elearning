<div class="book-header">
  <?php if ($provider_logo): ?>
    <div class="provider-logo">
      <?php print $provider_logo; ?>
    </div>
  <?php endif; ?>

  <div class="title-wrapper">
    <?php if ($course_title): ?>
      <div class="course-title">
        <?php print $course_title; ?>
      </div>
    <?php endif; ?>

    <?php if ($teacher_name || $teacher_surname): ?>
      <div class="teacher-name">
        <?php print $teacher_name . '&nbsp;' . $teacher_surname; ?>
      </div>
    <?php endif; ?>
  </div>
  <?php if (isset($lesson_link)) print $lesson_link; ?>
</div>
