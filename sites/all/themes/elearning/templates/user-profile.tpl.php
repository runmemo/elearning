<?php
/**
 * @file
 * Custom theme implementation to present all user profile data.
 *
 * @see user-profile.tpl.php in user module.
 */
?>
<div class="profile omega"<?php print $attributes; ?>>
  <div class="user-profile-name-caption alpha omega">
    <div class="user-name omega">
      <h2><?php print $account->name; ?></h2>
    </div>
    <?php if ($access) : ?>
    <div class="user-profile-edit-link omega">
      <h2><?php print l(t('Edit'), 'user/' . $account->uid . '/edit', array('attributes' => array('class' => array('profile-edit', 'ctools-modal-common-modal-style')))); ?></h2>
    </div>
    <?php endif; ?>
  </div>
  <div class="user-profile-main-panel alpha omega">
    <div class="user-profile-basic-info grid-6 alpha omega">
      <div class="user-profile-picture-points alpha">
        <div class="user-avatar-wrapper">
          <?php print render($user_profile['user_picture']); ?>
        </div>
        <div class="user-profile-userpoints">
          <?php print $userpoints_count; ?>
        </div>
      </div>
      <div class="user-profile-fields omega">
        <?php if (isset($field_first_name) || isset($field_surname)) : ?>
          <div class="user-profile-name-surname">
            <div class="user-profile-name-surname-caption"><?php print t('Name', array(), array('conext' =>'user full name')); ?></div>
            <?php if (isset($field_first_name)) print render($user_profile['field_first_name']); ?>
            <?php if (isset($field_surname)) print render($user_profile['field_surname']); ?>
          </div>
        <?php endif; ?>
        <div class="user-profile-email">
          <div class="field-label">
            <?php print t('E-mail'); ?>
          </div>
          <div class="field-item"><?php print $account->mail; ?></div>
        </div>
        <?php if (isset($field_birthday)) print render($user_profile['field_birthday']); ?>
        <?php if (isset($field_phone)) print render($user_profile['$field_phone']); ?>
      </div>
    </div>
    <?php if (isset($user_teaches_courses)) print $user_teaches_courses; ?>
    <?php if (isset($user_courses_view)) print $user_courses_view; ?>
  </div>
</div>
