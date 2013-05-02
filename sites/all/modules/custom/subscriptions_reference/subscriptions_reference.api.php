<?php

/**
 * @file
 * subscriptions_reference.api.php
 */

/**
 * Gets attributes of the reference field
 * @return array
 */
function hook_subscriptions_reference_info() {
   return array(
    'reference_id' => array( // should unique accross modules that implement that hook
      'parent' => 'parent_content_type',  // is being referenced
      'child' => 'child_content_type',    // contains the field
      'field' => 'my_reference_field'),   // name of the field
  );
}