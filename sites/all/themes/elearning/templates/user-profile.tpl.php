<?php
/**
 * @file
 * Custom theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
?>
<div class="profile omega"<?php print $attributes; ?>>
  <div class="user-profile-name-caption alpha omega">
    <div class="user-name omega">
      <h2><?php print $user_name; ?></h2>
    </div>
    <?php if ($access) : ?>
    <div class="user-profile-edit-link omega">
      <h2><?php print l(t('Edit'), 'user/' . $user_uid . '/edit', array('attributes' => array('class' => array('profile-edit', 'ctools-modal-common-modal-style')))); ?></h2>
    </div>
    <?php endif; ?>
  </div>
  <div class="user-profile-main-panel alpha omega">
    <div class="user-profile-basic-info grid-6 alpha omega">
      <div class="user-profile-picture-points alpha">
        <div class="user-profile-picture-edit">
          <div id="user-profile-picture">
            <?php if (isset($user_picture)) print $user_picture; ?>
          </div>
          <?php if ($access) : ?>
            <a class="user-picture-edit"><?php print t('Choose photo'); ?></a>
          <?php endif; ?>
        </div>
        <div class="user-profile-userpoints">
          <?php print $userpoints_count; ?>
        </div>
      </div>
      <div class="user-profile-fields omega">
        <?php if (isset($field_name) || isset($field_surname)) : ?>
          <div class="user-profile-name-surname">
            <div class="user-profile-name-surname-caption"><?php print t('Name'); ?></div>
            <?php if (isset($field_name)) print $field_name; ?>
            <?php if (isset($field_surname)) print $field_surname; ?>
          </div>
        <?php endif; ?>
        <div class="user-profile-email">
          <div class="field-label">
            <?php print t('E-mail') ?>
          </div>
          <div class="field-item"><?php print $user_mail; ?></div>
        </div>
        <?php if (isset($field_birthday)) print $field_birthday; ?>
        <?php if (isset($field_phone)) print $field_phone; ?>
      </div>
    </div>
    <?php if (isset($user_courses_view)) print $user_courses_view; ?>
  </div>
</div>
<div class="upload-form-background"></div>
<div class="upload-form-container">
  <?php if (isset($upload_form)) print render($upload_form); ?>
</div>
