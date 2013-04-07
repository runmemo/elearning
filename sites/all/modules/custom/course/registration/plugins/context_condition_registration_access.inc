<?php

/**
 * Exposes registration as context for items of the cousre
 */
class context_condition_registration_access extends context_condition {

  function condition_values() {
    $values = array();

    $values['registered'] = 'Registered';
    $values['not_registered'] = 'Not Registered';
    $values['none'] = 'Not part of course';

    return $values;
  }

  function execute($node, $account) {
    $access = course_user_access($node, $account);
    if (isset($access)) {
      if ($access) { // user has access to the content
        foreach ($this->get_contexts('registered') as $context) {
          $this->condition_met($context, 'registered');
        }
      }
      else 
      { // user does not have access
        foreach ($this->get_contexts('not_registered') as $context) {
          $this->condition_met($context, 'not_registered');
        }
      }
    }
    else 
    { // node is not part of the book or not at level of course content
      foreach ($this->get_contexts('none') as $context) {
        $this->condition_met($context, 'none');
      }
    }
  }

}