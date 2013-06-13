<?php

/**
 * Internal notifier.
 * 
 * Simple class, that imitates delivery in order to create instance between user
 * and message.
 */
class MessageNotifierInternal extends MessageNotifierBase {

  public function deliver(array $output = array()) {
    newsfeed_insert($this->plugin['options']['mid'], $this->message->uid, 0);
    return TRUE;
  }

}
