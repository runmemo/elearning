<?php

/**
 * Internal notifier.
 * 
 * Simple class, that imitates delivery in order to create instance between user
 * and message.
 */
class MessageNotifierInternal extends MessageNotifierBase {

  public function deliver(array $output = array()) {
    newsfeed_create_instance($this->plugin['options']['mid'], $this->message->uid);
    return TRUE;
  }

}
