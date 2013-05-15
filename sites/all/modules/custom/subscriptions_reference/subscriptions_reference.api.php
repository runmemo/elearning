<?php

/**
 * @file
 * subscriptions_reference.api.php
 */

/**
 * Gets attributes of the reference field that controls notifications.
 * 
 * Function returns an array with the information about referncing fields where 
 * each field is represented by an array with the following elements:
 * - 'parent': Content type that is being referenced.
 * - 'child': Content type that contains the referencing field.
 * - 'field': The name of the referencing field.
 * - 'ref_item': Element in the reference field that stores nid. 
 *    For field based on References module it will be 'nid.
 *    For fields based on Entity References it will be 'target_id'.
 * 
 * @return array
 *   Array as described above. 
 *   Keys of array should be unique accross modules that implement this hook.
 */
function hook_subscriptions_reference_info() {
   return array(
     // 
    'reference_id' => array( 
      'parent' => 'parent_content_type',  
      'child' => 'child_content_type',
      'field' => 'my_reference_field',
      'ref_item' => 'target_id'),  
  );
}