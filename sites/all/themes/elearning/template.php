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
    $field = field_view_field('node', $provider[0]['entity'], 'field_logo', array('label' => 'hidden', 'image_style' => 'provider_logo'));
    $vars['provider_logo'] = render($field);
    $vars['provider_name'] = $provider[0]['entity']->title;
  }
  // teacher logo and name
  $teacher = field_get_items('node', $node, 'field_teacher');
  if (isset($teacher[0])) {
    $field = field_view_field('user', $teacher[0]['user'], 'field_full_name', array('label' => 'hidden', 'image_style' => 'teacher_picture'));
    $vars['teacher_avatar'] = theme('user_picture', array('account' => $teacher[0]['user']));
    $vars['teacher_name'] = render($field);
  }
  // tmp image for social stuff
  $vars['tmp_social_img'] = $base_url . '/sites/all/themes/elearning/images/social-stuff.png';
  $vars['form_class_participate'] = drupal_get_form('course_registration_form');
   $vars['content']['field_video'][0]['file']['#options']['width'] = 440;
   $vars['content']['field_video'][0]['file']['#options']['height'] = 250;
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

/**
 * Preprocess for book navigation.
 * This is copy of template_preprocess_book_navigation() function.
 * We need this to alter book navigation list with lessons.
 */
function elearning_preprocess_book_navigation(&$variables) {
  $book_link = $variables['book_link'];
  $flat = book_get_flat_menu($book_link);
  $children = array();
  if ($book_link['has_children']) {
    // Walk through the array until we find the current page.
    do {
      $link = array_shift($flat);
    }
    while ($link && ($link['mlid'] != $book_link['mlid']));
    // Continue though the array and collect the links whose parent is this page.
    while (($link = array_shift($flat)) && $link['plid'] == $book_link['mlid']) {
      $data['link'] = $link;
      $data['below'] = '';
      $children[] = $data;
    }
  }
  if ($children) {
    // add "Section" part to the lesson title.
    $vars = array();
    foreach ($children as $key => $link) {
      $c = t('Section') . ' ' . ($key + 1) . '. ';
      $vars['items'][] = '<span class="course-section-number">' . t('Section') . ' ' . ($key + 1) . '. </span>' . l($link['link']['title'], $link['link']['href']);
    }
    $list = theme('item_list', $vars);
    if (!empty($list)) {
      $variables['tree'] = $list;
    }
  }
}
