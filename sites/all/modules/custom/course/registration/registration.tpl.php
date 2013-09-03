<?php

/*
 * Template file for registration entities.
 */

?>
<div id="registration-<?php print $registration->registration_id; ?>">
  <div class ='node'>
    <?php echo t('Registration for: ') . $content['node']->title; ?>
  </div>
  <div class ='user'>
    <?php echo t('By user: ') . $content['user']->name; ?>
  </div>
</div>