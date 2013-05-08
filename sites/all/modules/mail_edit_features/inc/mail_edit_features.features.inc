<?php

/**
 * @file
 * Features module support for Mail edit templates Export.
 */


/**
 * Implementation of hook_features_export()
 */
function mail_edit_features_features_export($data, &$export, $module_name = '') {
  $pipe = array();
  $export['dependencies']['features'] = 'features';
  $export['dependencies']['mail_edit'] = 'mail_edit';
  $export['dependencies']['mail_edit_features'] = 'mail_edit_features';

  if (!isset($export['features']['mail_edit_features'])) {
    $export['features']['mail_edit_features'] = array();
  }

  foreach ($data as $identifier) {
    list($id, $language) = explode('--', $identifier);
    $mail_edit_features = array(
      'machine_name' => $identifier,
      'table' => 'mail_edit',
      'type' => 'Normal',
      'export_type' => 1,
      'mail_edit' => array(
        'id' => $id,
        'language' => $language,
      )
    );
    $export['features']['mail_edit_features'][$identifier] = $identifier;
    $pipe['mail_edit'][] = $mail_edit_features;

    $mail_edit_features['mail_edit'] = array(
      'id' => $id,
      'language' => $language,
    );
    $mail_edit_features['machine_name'] = $identifier;
    $export['features']['mail_edit_features'][$identifier] = $identifier;
    $pipe['mail_edit'][] = $mail_edit_features;
  }
  return $pipe;
}

/**
 * Implementation of hook_features_export_options().
 */
function mail_edit_features_features_export_options() {
  $options = array();
  $query = db_query('SELECT me.id, me.language	FROM {mail_edit_registry} mer' .
    ' JOIN {mail_edit} me ON mer.id = me.id');

  foreach ($query as $result) {
    $options[$result->id . '--' . $result->language] = t('Template for @id (@lang)',
      array('@id' => $result->id, '@lang' => $result->language));
  }

  return $options;
}

/**
 * Implementation of hook_features_export_render().
 */
function mail_edit_features_features_export_render($module, $data) {
  $code = array();

  $code[] = '  $mail_edit_features = array();';
  $code[] = '';

  foreach ($data as $identifier) {
    $mail_edit_features = mail_edit_features_string_get($identifier);
    if (!empty($mail_edit_features)) {
      $code[] = '  // Exported mail edit: ' . check_plain($identifier);
      $code[] = '  $mail_edit_features' . "['{$identifier}'] = {$mail_edit_features}";
      $code[] = '';
    }
  }

  $code[] = '  return $mail_edit_features;';

  return array('default_mail_edit_features' => implode("\n", $code));
}

/**
 * Implementation of hook_features_export_rebuild()
 */
function mail_edit_features_features_rebuild($module) {

  if ($defaults = features_get_default('mail_edit_features', $module)) {
    $current_templates = mail_edit_features_content_get();

    foreach ($defaults as $default_mail_template) {
      $identifier = $default_mail_template['id'] . '--' . $default_mail_template['language'];

      // Template already exists in DB - update it.
      if (isset($current_templates[$identifier])) {
        drupal_write_record('mail_edit', $default_mail_template, array('id', 'language'));

        // Due avoid name conflict with same field names 
        // we use registry_description for description in registry table
        $default_mail_template['description'] = isset($default_mail_template['registry_description'])
          ? $default_mail_template['registry_description'] : '';
        drupal_write_record('mail_edit_registry', $default_mail_template, array('id'));
      }
      // Insert new
      else {
        drupal_write_record('mail_edit', $default_mail_template);

        $default_mail_template['description'] = isset($default_mail_template['registry_description'])
          ? $default_mail_template['registry_description'] : '';
        drupal_write_record('mail_edit_registry', $default_mail_template);
      }
    }
    // @TODO Here should be deletion of removed templates
  }
}

/**
 * Implementation of hook_features_revert().
 */
function mail_edit_features_features_revert($module) {
  mail_edit_features_features_rebuild($module);
}
