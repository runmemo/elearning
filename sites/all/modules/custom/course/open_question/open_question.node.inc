<?php

/**
 * Implements hook_node_info().
 */
function open_question_node_info() {
  $items = array(
    'open_question' => array(
      'name' => t('Open Question'),
      'base' => 'node_content',
      'description' => t('Represents open questions that can be part of the course and can be answered by a student.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'open_question_answer' => array(
      'name' => t('Open Question Answer'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'open_question_feedback' => array(
      'name' => t('Open Question Feedback'),
      'base' => 'node_content',
      'description' => t('Feedback provided to the user by other students on the Open Questions page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_node_view().
 */
function open_question_node_view($node, $view_mode, $langcode) {
  if ($node->type == 'open_question') {
    drupal_add_js(drupal_get_path('module', 'open_question') . '/open_question.js');
  }
}

/**
 * Implements hook_node_insert().
 */
function open_question_node_insert($node) {
  if ($node->type == 'open_question_feedback') {
    open_question_new_feedback_notify($node);
  }
}

/**
 * Notifies open question answer author if new feedback is posted.
 * 
 * @param object $feedback
 *   Node object of new feedback.
 */
function open_question_new_feedback_notify($feedback) {
  if (!module_exists('newsfeed')) {
    watchdog('open_question', 'Enable newsfeed module to notify users of new content.', array(), WATCHDOG_WARNING);
    return;
  }
  $feedback_wrapper = entity_metadata_wrapper('node', $feedback);
  $fields = array(
    'field_message_feedback' => $feedback->nid,
    'field_message_open_question' => $feedback_wrapper->field_open_question_answer->field_open_question->value()->nid,
  );
  $uids = array(
    $feedback_wrapper->field_open_question_answer->value()->uid => array(
      'notifiers' => array(
        'internal' => 'internal'
      )
    )
  );
  newsfeed_create_message('answer_feedback_notification', $feedback->uid, $feedback, $fields, $uids);
}
