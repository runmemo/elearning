<?php

/**
 * Internal notifier.
 * 
 * Simple class, that imitates delivery in order to create instance between user
 * and message.
 */
class MessageNotifierInternal extends MessageNotifierBase {

  public function deliver(array $output = array()) {
    $record = array('mid' => $this->plugin['options']['mid'], 'uid' => $this->message->uid);
    drupal_write_record('message_user', $record);
    return TRUE;
  }

}
