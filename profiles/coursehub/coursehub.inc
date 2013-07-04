<?php

/**
 * @file
 * Contains Batch API callbacks used during installation.
 */

/**
 * BatchAPI callback.
 *
 * @see coursehub_install_custom_modules()
 */
function _coursehub_enable_module($module, $module_name, &$context) {
  module_enable(array($module), FALSE);
  $context['message'] = st('Installed %module module.', array('%module' => $module_name));
}

/**
 * BatchAPI callback.
 *
 * @see coursehub_install_custom_modules()
 */
function _coursehub_flush_cache($message, &$context) {
  features_flush_caches();
  drupal_flush_all_caches();
  $context['message'] = $message;
}
