<?php
// @todo barinder
// provide comments for the variables available in this tpl.php file.
?>
<div class="book-header">
    <div class="provider-logo">
      <?php print $provider_logo; ?>
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
