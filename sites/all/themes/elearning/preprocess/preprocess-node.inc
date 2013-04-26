<?php


/**
 * Preprocess for node view.
 * @param array $variables
 */
function elearning_alpha_preprocess_node(&$variables) {
  // global preprocessing of node
  unset($variables['content']['links']['statistics']['#links']['statistics_counter']['title']);

  // call node specific preprocessors
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables);
  }
}

/**
 * Preprocess for node-type "Course" view.
 * @param array $vars
 */
function elearning_alpha_preprocess_node_course(&$vars) {
  global $base_url;
  $node = $vars['node'];
  // provider logo and name
  $provider = field_get_items('node', $node, 'field_provider');
  if (isset($provider[0])) {
    $field_logo = field_view_field('node', $provider[0]['entity'], 'field_logo', array('label' => 'hidden', 'settings' => array('image_style' => 'provider_logo')));
    if (empty($field_logo)) {
      $vars['provider_logo'] = '<div class="provider-logo-default"></div>';
    }
    else {
      $vars['provider_logo'] = render($field_logo);
    }
    $field_extra = field_view_field('node', $provider[0]['entity'], 'field_provider_extra', array('label' => 'hidden'));   
    $vars['provider_extra'] = render($field_extra);
    $vars['provider_name'] = $provider[0]['entity']->title;
  }
  // teacher logo and name
  $teacher = field_get_items('node', $node, 'field_teacher');
  if (isset($teacher[0])) {
    $teacher_account = $teacher[0]['user'];
    $field_name = field_view_field('user', $teacher_account, 'field_name', array('label' => 'hidden'));
    $field_surname = field_view_field('user', $teacher_account, 'field_surname', array('label' => 'hidden'));
    $vars['teacher_avatar'] = elearning_get_user_picture($teacher_account, '', 'user-profile');
    $vars['teacher_name'] = render($field_name);
    $vars['teacher_surname'] = render($field_surname);
  } 
  else {
    $vars['teacher_avatar'] = '';
    $vars['teacher_name'] = '';
    $vars['teacher_surname'] = '';
  }
  // tmp image for social icons
  $vars['tmp_social_img'] = $base_url . '/sites/all/themes/elearning/images/social-stuff.png';
  $vars['form_class_participate'] = drupal_get_form('course_registration_form');
  // students view
  $view = views_get_view('course_students'); 
  $vars['students_view'] = $view->preview('block', array($node->nid));
}

/**
 * Preprocess for node-type "Question" view.
 * @param array $vars
 */
function elearning_alpha_preprocess_node_question(&$vars) {
  $vars['userpoints_count'] = userpoints_get_current_points($vars['uid'], 'all');
  $vars['user_picture'] = elearning_get_user_picture($vars['uid'], 'question_author', 'node-question');
  $vars['created_formatted'] = t('%time ago', array('%time' => format_interval(REQUEST_TIME - $vars['created'], 1)));
}

/**
 * Preprocess for node-type "Open Question" view.
 * @param array $vars
 */
function elearning_alpha_preprocess_node_open_question(&$vars) {
  $vars['display_submitted'] = FALSE;
  $vars['user_picture'] = elearning_get_user_picture($vars['uid'], 'question_author', 'node-question');
}


function elearning_alpha_preprocess_node_certificate(&$vars) {
  if (($vars['elements']['#view_mode'] == 'print') 
      && isset($vars['elements']['#print_format'])) {
     // $vars['node_title_custom'] = $vars['node']->title;
  }
  
}