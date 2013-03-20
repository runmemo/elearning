<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */
 
 function set_id_class($type){
  $id='id="content-group"';
  if ($type == 'course'){
    $id='id="content-group-node"';
  }
  return $id;
}

function elearning_preprocess_node(&$variables, $hook) {
  
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  } 
}

function elearning_preprocess_views_view(&$vars) {
  if (isset($vars['view']->name)) {
    $function = __FUNCTION__ . '_' . $vars['view']->name; 
    if (function_exists($function)) {
     $function($vars);
    }
  }
}


function elearning_preprocess_node_course(&$vars, $hook) {
  
  $node = $vars['node'];
  // $provider_logo variable
  $providers = field_get_items('node', $node, 'field_provider');
  foreach($providers as $provider) {
    $vars['provider_logo'] = render(field_view_field('node', $provider['entity'], 'field_logo'));
    break; // there should be only one value
  }
  
  // $teacher_avatar variable
  $teachers = field_get_items('node', $node, 'field_teacher');
  foreach ($teachers as $teacher) {     
     $vars['teacher_avatar'] = theme('user_picture', array('account' => $teacher['user']));
     break; // there should be only one value
  }
  
}


?>