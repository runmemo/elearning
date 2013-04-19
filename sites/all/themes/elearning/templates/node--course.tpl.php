<?php
/**
 * @file node-course.tpl.php
 * Template for course nodes.
 *
 * Available variables:
 * - $provider_logo: Provider's logo image
 * - $provider_name: Name of the course provider
 * - $provider_extra: Additional information about provider
 * - $tmp_social_img: temporary image, representing social iframes
 * - $teacher_name: Field "Name" of the user, who is the course teacher
 * - $teacher_surname: Field "Surame" of the user, who is the course teacher
 * - $teacher_avatar: HTML, representing teacher's picture
 * - $form_class_participate: form for participating in the course
 * - $students_view: embedded view with students, which are already participats
 * - $content: node content
 * 
 * All variables available in node.tpl.php
 * @todo Ilya provide documentation for variables introduced in template.php
 */
?>
<article<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <div class="node-course-header">
      <div class="node-course-header-left grid-10 omega">
        <?php print $provider_logo; ?>
        <div class ="node-course-provider-name">
          <h1 class="title course-title" id="page-title"><?php print $node->title; ?></h1>
          <?php if (isset($provider_name) || isset($provider_extra)) : ?>
            <div class="provider-name-extra grid-4 omega">
              <div class="provider-name">
                <?php if (isset($provider_name)) print $provider_name; ?>
              </div>
              <?php if (isset($provider_extra)) print $provider_extra; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
      <div class="social-share grid-3 omega"><img src="<?php print $tmp_social_img; ?>"></div>
    </div>
    <div class="node-course-basic-info">
      <div class="node-course-teacher-parameters">
        <?php if (isset($teacher_name) || isset($teacher_surname)) : ?>
          <h2><?php print $teacher_name . $teacher_surname; ?></h2>
        <?php endif; ?>
        <div class="node-course-teacher-button">
          <div id="user-profile-picture">
            <?php print $teacher_avatar; ?>
          </div>
          <?php if (isset($form_class_participate)) print render($form_class_participate); ?>
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