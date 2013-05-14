<?php
/**
 * @file
 * Course certificate print module template
 *
 * @ingroup print
 * 
 * @todo Ilya: 
 *   -  remove node-.. from css classes. 
 *   -  can we use certificate.css file for css specific to this template?
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $print['language']; ?>" xml:lang="<?php print $print['language']; ?>">
  <head>
    <?php print $print['head']; ?>
    <?php print $print['base_href']; ?>
    <title><?php print $print['title']; ?></title>
    <?php print $print['scripts']; ?>
    <?php print $print['sendtoprinter']; ?>
    <?php print $print['robots_meta']; ?>
    <?php print $print['favicon']; ?>
    <?php print $print['css']; ?>
    <style type="text/css" media="all">
      @import url("<?php print $base_url ?>/sites/all/themes/elearning/css/print.css");
    </style>
  </head>
  <body>
    <div class="node-certificate-wrapper">
      <div class="node-certificate-title">
        <?php print t('Coursehub'); ?>
        <span class="node-certificate-registered"><?php print '&reg;'; ?></span>
      </div>
      <?php if (isset($student['name'])) : ?>
        <div class="node-certificate-body">
          <div class="node-certificate-desc">
            <div class="desc-text"><?php print t('This certificate confirms that'); ?></div>
          </div>
          <div class="node-certificate-course-info">
            <div class="inner-text"><?php if (isset($student['name'])) print $student['name']; ?></div>
          </div>
          <div class="node-certificate-desc">
            <div class="desc-text"><?php print t('successfully attended a course'); ?></div>
          </div>
          <?php if (isset($course['title'])) : ?>
            <div class="node-certificate-course-info">
              <div class="inner-text"><?php print $course['title']; ?></div>
            </div>
          <?php endif; ?>
          <div class="node-certificate-desc">
            <div class="desc-text"><?php print t('with result'); ?></div>
          </div>
          <?php if (isset($course['grade_score'])) : ?>
            <div class="node-certificate-course-info certificate-grade">
              <div class="grade-name"><?php print $course['grade_score'] . ' ' . t('(out of !count)', array('!count' => 100)); ?></div>
              <div class="grade-score"><?php print $course['grade_name']; ?></div>
            </div>
          <?php endif; ?>
        </div>
      <?php endif; ?>
      <ul class="node-certificate-bottom">
        <li class="node-certificate-provider-logo">
          <?php if (isset($course['provider_logo'])) print $course['provider_logo']; ?>
        </li>
        <li class="node-certificate-signature-wrapper">
          <ul class="node-certificate-signature">
            <li class="node-certificate-teacher-name">
              <?php if (isset($course['teacher_name'])) print $course['teacher_name']; ?>
              <?php if (isset($course['teacher_surname'])) print $course['teacher_surname']; ?>
            </li>
            <li class="node-certificate-teacher-signature">
              <?php if (isset($course['teacher_signature'])) print $course['teacher_signature']; ?>
            </li>
          </ul>
        </li>
      </ul>
    </div>
  </body>
</html>