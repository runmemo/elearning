<?php
/**
 * @file node-course.tpl.php
 * Template for course nodes.
 *
 * Available variables:
 * - $provider: Array with Provider's logo image, name and extra fields.
 * - $teacher: Array representing fields "Name", "Surame" and user picture
 *             of the user, who is the course teacher
 * - $form_class_participate: form for participating in the course
 * - $students_view: embedded view with students, which are already participats
 * - $content: node content
 * 
 * All variables available in node.tpl.php
 */
?>
<article<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <div class="node-course-header">
      <div class="node-course-header-left grid-10 omega">
        <?php if (isset($provider['logo'])) print $provider['logo']; ?>
        <div class ="node-course-provider-name">
          <h1 class="title course-title" id="page-title"><?php print $node->title; ?></h1>
          <?php if (isset($provider['name']) || isset($provider['extra'])) : ?>
            <div class="provider-name-extra grid-4 omega">
              <div class="provider-name">
                <?php if (isset($provider['name'])) print $provider['name']; ?>
              </div>
              <?php if (isset($provider['extra'])) print $provider['extra']; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
      <div class="social-share grid-4 omega"></div>
    </div>
    <div class="node-course-basic-info">
      <div class="node-course-teacher-parameters">
        <h2><?php print $teacher['teacher_name'] ?></h2>
        <div class="node-course-teacher-button">
          <div class="teacher-avatar">
            <?php print $teacher['avatar']; ?>
          </div>
          <?php print render($content['form_class_participate']); ?>
        </div>
        <div class="node-course-paramenters">
          <?php if (isset($content['field_duration'])) print render($content['field_duration']); ?>
          <?php if (isset($content['field_course_load'])) print render($content['field_course_load']); ?>
        </div>
      </div>
      <?php if (isset($content['field_video'])) print render($content['field_video']); ?>
    </div>
    <div class="node-course-description-students">
      <div class="node-course-description grid-10 omega">
        <?php if (isset($content['body'])) print render($content['body']); ?>
        <?php if (isset($content['field_course_content'])) print render($content['field_course_content']); ?>
      </div>
      <?php if (isset($students_view)) print $students_view; ?>
    </div>

  </div>
</article>