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
    <div class='webform grid-10 alpha'>
      <?php print drupal_render($content['body']); ?>
      <?php print drupal_render($content['webform']); ?>
    </div>
    <div class='grid-6 webform-sidebar-second omega'>
      <div class='webform-action-call'>
        <?php print drupal_render($content['field_image']); ?>
      </div>
    </div>
  </div>
</article>