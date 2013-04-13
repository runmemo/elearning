<?php
/**
 * @file
 * widget.tpl.php
 *
 * Elearning UpAndDown widget theme for Vote Up/Down
 */
?>
<div class="vud-widget vud-widget-elearning_widget" id="<?php print $id; ?>">
  <div class="up-score clear-block">
    <?php if ($show_links): ?>
      <?php if ($show_up_as_link): ?>
        <a href="<?php print $link_up; ?>" rel="nofollow" class="<?php print "$link_class_up"; ?>" title="<?php print t('Vote up!'); ?>">
      <?php endif; ?>
          <div class="<?php print $class_up; ?>" title="<?php print t('Vote up!'); ?>"></div>
          <div class="element-invisible"><?php print t('Vote up!'); ?></div>
      <?php if ($show_up_as_link): ?>
        </a>
      <?php endif; ?>
    <?php endif; ?>
  </div>
  <div class="<?php print $current_class; ?>"><?php print $current_points; ?></div>
  <div class="down-score clear-block">
    <?php if ($show_links): ?>
      <?php if ($show_down_as_link): ?>
        <a href="<?php print $link_down; ?>" rel="nofollow" class="<?php print "$link_class_down"; ?>" title="<?php print t('Vote down!'); ?>">
      <?php endif; ?>
          <div class="<?php print $class_down; ?>" title="<?php print t('Vote down!'); ?>"></div>
          <div class="element-invisible"><?php print t('Vote down!'); ?></div>
      <?php if ($show_down_as_link): ?>
        </a>
      <?php endif; ?>
    <?php endif; ?>
  </div>
  <?php if ($show_reset): ?>
    <a href="<?php print $link_reset; ?>" rel="nofollow" class="<?php print $link_class_reset; ?>" title="<?php print $reset_long_text; ?>">
      <div class="<?php print $class_reset; ?>">
        <?php print $reset_short_text; ?>
      </div>
    </a>
  <?php endif; ?>
</div>
