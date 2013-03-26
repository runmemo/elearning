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

/**
 * Preprocess for node view.
 */
function elearning_preprocess_node(&$variables, $hook) {
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  } 
}

/**
 * Preprocess for views view.
 */
function elearning_preprocess_views_view(&$vars) {
  if (isset($vars['view']->name)) {
    $function = __FUNCTION__ . '_' . $vars['view']->name; 
    if (function_exists($function)) {
     $function($vars);
    }
  }
}

/**
 * Preprocess for node-type "Course" view.
 */
function elearning_preprocess_node_course(&$vars, $hook) {
  global $base_url;
  $node = $vars['node'];
  // provider logo and name
  $provider = field_get_items('node', $node, 'field_provider');
  if(isset($provider[0])) {
    $field_logo = field_view_field('node', $provider[0]['entity'], 'field_logo', array('label' => 'hidden', 'image_style' => 'provider_logo'));
    $field_extra = field_view_field('node', $provider[0]['entity'], 'field_provider_extra', array('label' => 'hidden'));
    $vars['provider_logo'] = render($field_logo);
    $vars['provider_extra'] = render($field_extra);
    $vars['provider_name'] = $provider[0]['entity']->title;
  }
  // teacher logo and name
  $teacher = field_get_items('node', $node, 'field_teacher');
  if (isset($teacher[0])) {
    $field_name = field_view_field('user', $teacher[0]['user'], 'field_name', array('label' => 'hidden'));
    $field_surname = field_view_field('user', $teacher[0]['user'], 'field_surname', array('label' => 'hidden'));
    $vars['teacher_avatar'] = theme('user_picture', array('account' => $teacher[0]['user']));
    $vars['teacher_name'] = render($field_name);
    $vars['teacher_surname'] = render($field_surname);
  }
  // tmp image for social icons
  $vars['tmp_social_img'] = $base_url . '/sites/all/themes/elearning/images/social-stuff.png';
  $vars['form_class_participate'] = drupal_get_form('course_registration_form');
   $vars['content']['field_video'][0]['file']['#options']['width'] = 448;
   $vars['content']['field_video'][0]['file']['#options']['height'] = 243;
   // students view
   $view = views_get_view('course_students');
   $vars['students_view'] = $view->preview('block', array($node->nid));
}

/**
 * Preprocess for HTML view.
 */
function elearning_preprocess_html(&$vars, $hook) {
  // hide page title if we are on "Course" node.
  $vars['show_title'] = isset($vars['page']['content']['content']['content']['system_main']['nodes'][1]['title_field']) ? TRUE : FALSE;
}

