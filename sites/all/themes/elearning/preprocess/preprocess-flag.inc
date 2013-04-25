<?php

/**
 * Implements hook_preprocess_block
 * Function redirects processing to functions that are buld of hook plus flag name
 * @see elearning_preprocess_flag__abuse_content
 */
function elearning_alpha_preprocess_flag(&$vars) {
  if (isset($vars['flag'])) {  
    $function = __FUNCTION__ . '__' . $vars['flag']->name;
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Preprocessing for abuse_content flag adds ctools modal support
 */
function elearning_alpha_preprocess_flag__abuse_content(&$vars) {
  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();
  $vars['link']['href'] .= '/nojs';
  $vars['link_href'] = isset($vars['link']['href']) ? check_url(url($vars['link']['href'], $vars['link'])) : FALSE;
  $vars['flag_classes_array'][] = 'ctools-use-modal';
  $vars['flag_classes_array'][] = 'ctools-modal-common-modal-style';
  $vars['flag_classes_array'][] = 'ctools-modal-abuse';
  $vars['flag_classes'] = implode(' ', $vars['flag_classes_array']); 
}
