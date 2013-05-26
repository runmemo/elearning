<?php

/**
 * @file
 * Extention of theme implementation to present a picture configured for the
 * user's account.
 *
 * Available variables:
 * - $show_points - defines wether points should be shown allong with the picture.
 * - $userpoints - number of user points for the user.
 * - $size - defines the size of the image to be shown.
 * 
 * @see template_preprocess_user_picture() for default variables.
 */
?>
<div class="<?php print $size; ?>-avatar">
  <?php 
    if (!empty($user_picture)) {
      print $user_picture; 
    }
  ?>
  <?php if (isset($userpoints)): ?>
    <div class="author-points">
         <?php print $userpoints; ?>
    </div>
   <?php endif; ?>
</div>