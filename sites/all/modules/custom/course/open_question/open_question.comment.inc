<?php


/**
 * Implements hook_comment_insert().
 * 
 * Creates notification message on commenting feedback.
 */
function open_question_comment_insert($comment) {
  $node = node_load($comment->nid);
  if ($node->type == 'open_question_feedback') {
    open_question_new_feedback_comment_notify($comment, $node);
  }
}

/**
 * Notifies open question answer author or feedback author if new comment is posted.
 * 
 * @param object $comment
 *   Comment object of new comment.
 * @param object $feedback
 *   Node object of the feedback.
 */
function open_question_new_feedback_comment_notify($comment, $feedback) {
  if (!module_exists('newsfeed')) {
    watchdog('open_question', 'Enable newsfeed module to notify users of new content.', array(), WATCHDOG_WARNING);
    return;
  }
  $feedback_wrapper = entity_metadata_wrapper('node', $feedback);
  if ($comment->uid == $feedback_wrapper->field_open_question_answer->value()->uid) {
    // If comment author is answer author, send message to feedback author.
    $type = 'oqaf_reviewer_comment_notification';
    $uid = $feedback->uid;
  } elseif ($comment->uid == $feedback->uid) {
    // If comment author is feedback author, send message to answer author.
    $type = 'oqaf_author_comment_notification';
    $uid = $feedback_wrapper->field_open_question_answer->value()->uid;
  } else {
    $uid = FALSE;
  }
  if (!$uid) {
    watchdog('open_question', 'Wrong uid on inserting new comment # @cid for feedback # @nid', array('@cid' => $comment->cid, '@nid' => $feedback->nid), WATCHDOG_WARNING);
    return;
  }
  $fields = array(
    'field_message_comment' => $comment->cid,
    'field_message_feedback' => $feedback->nid
  );
  $uids = array(
    $uid => array(
      'notifiers' => variable_get('message_subscribe_default_notifiers', array('internal' => 'internal')),
    )
  );
  newsfeed_create_message($type, $comment->uid, $feedback, $fields, $uids);
}
