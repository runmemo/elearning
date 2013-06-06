<?php

/**
 * @file
 * newsfeed.views.inc
 */

/**
 * Implements hook_views_data().
 */
function newsfeed_views_data() {
  $data = array();

  $data['message_user']['table']['group'] = t('Message-User instance');

  $data['message_user']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Message-User instance'),
    'help' => t('An instance between Message and User entities.'),
  );

  $data['message_user']['table']['default_relationship'] = array(
    'message' => array(
      'table' => 'message',
      'field' => 'mid',
    ),
  );

  $data['message_user']['table']['join'] = array(
    'message' => array(
      'left_field' => 'mid',
      'field' => 'mid',
    ),
  );

  $data['message_user']['mid'] = array(
    'title' => t('Instance message ID'),
    'help' => t('Message ID'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'title' => t('Message ID fliter'),
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('mid -> Message'),
      'handler' => 'views_handler_relationship',
      'base' => 'message',
      'base field' => 'mid',
      'field' => 'mid',
      'label' => t('message'),
      'help' => t('Use this relationship in order to load Message fields.'),
    ),
  );
  $data['message_user']['uid'] = array(
    'title' => t('Instance user ID'),
    'help' => t('User ID'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'title' => t('Instance user ID filter'),
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'help' => t('User ID'),
    ),
    'relationship' => array(
      'title' => t('uid -> User'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'field' => 'uid',
      'label' => t('users'),
      'help' => t('Use this relationship in order to load User fields.'),
    ),
  );
  return $data;
}
