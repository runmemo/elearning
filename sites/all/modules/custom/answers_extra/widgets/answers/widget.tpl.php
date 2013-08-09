<?php
/**
 * @file
 * widget.tpl.php
 *
 * Elearning UpAndDown widget theme for Vote Up/Down
 */
?>
<div class="vud-widget vud-widget-answers<?php if (!$vote_access) print ' vud-widget-inactive' ?>" id="<?php print $id; ?>">
  <div class="up-score clear-block">
    <?php if ($show_links): ?>
      <?php if ($show_up_as_link && $vote_access): ?>
        <a href="<?php print $link_up; ?>" rel="nofollow" class="<?php print $link_class_up; ?>" title="<?php print $title_text_up; ?>">
      <?php endif; ?>
          <div class="<?php print $class_up; ?>" title="<?php print $title_text_up; ?>"></div>
      <?php if ($show_up_as_link && $vote_access): ?>
        </a>
      <?php endif; ?>
    <?php endif; ?>
  </div>
  <div class="current-points <?php print $current_class; ?>"><?php print $current_points; ?></div>
  <div class="down-score clear-block">
    <?php if ($show_links): ?>
      <?php if ($show_down_as_link && $vote_access): ?>
        <a href="<?php print $link_down; ?>" rel="nofollow" class="<?php print $link_class_down; ?>" title="<?php print $title_text_down; ?>">
      <?php endif; ?>
          <div class="<?php print $class_down; ?>" title="<?php print $title_text_down; ?>"></div>
      <?php if ($show_down_as_link && $vote_access): ?>
        </a>
      <?php endif; ?>
    <?php endif; ?>
  </div>
  <?php if ($show_reset && $vote_access): ?>
    <a href="<?php print $link_reset; ?>" rel="nofollow" class="<?php print $link_class_reset; ?>" title="<?php print $reset_long_text; ?>">
      <div class="<?php print $class_reset; ?>">
        <?php print $reset_short_text; ?>
      </div>
    </a>
  <?php endif; ?>
</div>
