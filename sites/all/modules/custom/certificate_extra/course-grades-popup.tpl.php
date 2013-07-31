<?php
// File contains template for course grade hover pop-up.
?>
<div class="outline-certificate-circles">
  <div class="circles-inner">
    <div class="outline-circle"></div>
    <div class="outline-circle middle"></div>
    <div class="outline-circle"></div>
  </div>
</div>
<div class="outline-certificate-border"></div>
<div class="outline-certificate">
  <?php if (isset($points)) : ?>
    <div class="outline-certificate-points">
      <div class="outline-certificate-star"></div>
      <span class="outline-certificate-text"><?php print $points ?></span>
      <?php if (isset($grade_ranges) && !empty($grade_ranges)) : ?>
        <div class="tooltip-wrapper">
          <div class="tooltip-triangle"></div>
          <div class="tooltip-header"><?php print t('Compliance scores and marks for the certificate'); ?></div>
          <div class="tooltip-content">
            <ul class="course-outline-grades-list">
              <?php
              $count = count($grade_ranges);
              $i = 0;
              foreach ($grade_ranges as $range => $name):
                ?>
                <li <?php print $i ? '' : 'class="first"'; ?><?php print $i + 1 == $count ? 'class="last"' : ''  ?>>
                  <span class="grade-points-range"><?php print t('!range points', array('!range' => $range)); ?></span>
                  <span class="grade-points-desc"> - <?php print $name ?></span>
                </li>
                <?php
                $i++;
              endforeach;
              ?>
            </ul>
          </div>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <div class="outline-certificate-link <?php print $class ?>">
    <div class="outline-certificate-doc"></div>
    <?php print $link ?>
  </div>
</div>
<div class="outline-certificate-border"></div>