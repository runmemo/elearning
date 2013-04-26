<?php
/**
 * @file
 * provides html within modal form that allows to leave the course
 *
 * variables:
 * 	$disclaimer - text asking for confirmation
 * 	$leave_button - button that cancels registration for the course
 * 	$cancel_button - button that closes the modal window
 */
?>
<div class="course-title">
 <?php print $disclaimer; ?>
</div>
<div class="course-actions">
  <div class="course-exit-action">
    <?php print $leave_button; ?>
  </div>
  <div class="course-cancel-action">
    <?php print $cancel_button; ?>
  </div>
</div>