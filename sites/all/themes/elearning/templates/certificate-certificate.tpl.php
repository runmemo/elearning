<?php
/**
 * @file certificate.tpl.php
 * Course certificate print module template
 *
 * Available variables:
 * - $language: language, that is in use on the site
 * - $head: meta tags for head section
 * - $base_url: string, representing base url of the site
 * - $student_name: name of student, that is going to recieve certificate
 * - $course: array with course information (title, provider's logo, teacher's name and signature)
 * 
 * @ingroup print
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" dir="LTR" lang="<?php print $language; ?>" xml:lang="<?php print $language; ?>">
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <style type="text/css" media="all">
      @import url("<?php print $base_url ?>/sites/all/themes/elearning/css/certificate.css");
    </style>
  </head>
  <body>
    <div class="wrapper">
      <div class="title">
        <?php print t('Coursehub'); ?>
        <span class="registered"><?php print '&reg;'; ?></span>
      </div>
      <?php if (isset($student_name)) : ?>
        <div class="body">
          <div class="desc">
            <div class="desc-text"><?php print t('This certificate confirms that'); ?></div>
          </div>
          <div class="info">
            <div class="inner-text"><?php print $student_name; ?></div>
          </div>
          <div class="desc">
            <div class="desc-text"><?php print t('successfully attended a course'); ?></div>
          </div>
          <?php if (isset($course['title'])) : ?>
            <div class="info">
              <div class="inner-text"><?php print $course['title']; ?></div>
            </div>
          <?php endif; ?>
          <div class="desc">
            <div class="desc-text"><?php print t('with result'); ?></div>
          </div>
          <?php if (isset($course['grade_score'])) : ?>
            <div class="info grade">
              <div class="grade-name"><?php print $course['grade_score'] ?></div>
              <div class="grade-score"><?php print $course['grade_name']; ?></div>
            </div>
          <?php endif; ?>
        </div>
      <?php endif; ?>
      <ul class="bottom">
        <li class="provider-logo">
          <?php if (isset($course['provider_logo'])) print $course['provider_logo']; ?>
        </li>
        <li class="signature-wrapper">
          <ul class="signature">
            <li class="teacher-name">
                <?php if (isset($course['teacher_name'])) print $course['teacher_name']; ?>
                <?php if (isset($course['teacher_surname'])) print $course['teacher_surname']; ?>
            </li>
            <li class="teacher-signature">
              <?php if (isset($course['teacher_signature'])) print $course['teacher_signature']; ?>
            </li>
          </ul>
        </li>
      </ul>
    </div>
  </body>
</html>