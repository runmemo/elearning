<?php

/*
 ** @file
 *  Views declarations for our custom handler.
 */

/**
 * Implements hook_views_handlers().
 *
 * @return array
 */
function inline_comments_extra_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'inline_comments_extra') . '/views',
    ),
    'handlers' => array(
      'inline_comments_extra_handler_field_inline_comments' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}


/**
 * Implements hook_views_data().
 *
 * @return array
 */
function inline_comments_extra_views_data_alter(&$data) {
  $data['node_comment_statistics']['comment_count'] = array(
    'title' => t('Custom Inline Comments'),
    'help' => t('Custom field for displaying ajax comments'),
    'field' => array(
      'handler' => 'inline_comments_extra_handler_field_inline_comments',
       'notafield' => TRUE,
    ),
  );
}