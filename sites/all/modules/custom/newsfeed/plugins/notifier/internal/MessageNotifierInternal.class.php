<?php

/**
 * Internal notifier.
 * 
 * Simple class, that imitates delivery in order to make "MessageNotifierBase"
 * save message for every user.
 */
class MessageNotifierInternal extends MessageNotifierBase {

  public function deliver(array $output = array()) {
    // Just pass TRUE in order to save message.
    return TRUE;
  }
  
}
