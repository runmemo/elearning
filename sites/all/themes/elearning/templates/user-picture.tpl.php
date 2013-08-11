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
<div class="<?php print $size; ?>-avatar<?php if (!empty($upload_form)) print ' js-avatar'; ?>">
  <div id="js-user-avatar">
    <?php
    if (!empty($user_picture)) {
      print $user_picture;
    }
    ?>
  </div>
  <?php if ($show_points && isset($userpoints)): ?>
    <div class="author-points">
      <?php print $userpoints; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($upload_form)) : ?>
    <a class="user-avatar-edit-link js-avatar-edit">
      <?php print t('Choose photo'); ?>
    </a>
    <div class="js-modal"> 
      <div class="overlay-background js-modal-out"></div>
      <div class="upload-form-container js-modal-in">
        <?php print render($upload_form); ?>
      </div>
    </div>
  <?php endif; ?>
</div>