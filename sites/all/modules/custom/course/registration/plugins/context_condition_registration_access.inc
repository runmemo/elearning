<?php

/**
 * Exposes registration as context for items of the cousre
 */
class context_condition_registration_access extends context_condition {

  function condition_values() {
    $values = array();

    $values['true'] = 'Registered';
    $values['false'] = 'Not Registered';
    $values['none'] = 'Not part of course';

    return $values;
  }

  function execute($access) { 
    foreach ($this->get_contexts($access) as $context) {
          $this->condition_met($context, $access);
    }
  } 
   
}