<?php
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
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
      <?php if (isset($popup_description) && !empty($popup_description)) : ?>
        <div class="outline-certificate-desc-wrapper">
          <div class="outline-certificate-desc-triangle"></div>
          <?php print $popup_description; ?>
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