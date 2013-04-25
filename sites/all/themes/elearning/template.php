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

/**
 * Preprocess for node view.
 * @param array $variables
 * @param string $hook
 */
function elearning_preprocess_node(&$variables, $hook) {
  // global preprocessing of node
  unset($variables['content']['links']['statistics']['#links']['statistics_counter']['title']);

  // call node specific preprocessors
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}

/**
 * Preprocess for views view.
 * @param array $vars
 */
function elearning_preprocess_views_view(&$vars) {
  if (isset($vars['view']->name)) {
    $function = __FUNCTION__ . '__' . $vars['view']->name;
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Preprocess for "course_students" view.
 * @param array $vars
 */
function elearning_preprocess_views_view__course_students(&$vars) {
  $vars['classes_array'][] = 'grid-4';
  $vars['classes_array'][] = 'omega';
}

/**
 * Preprocess for "user_courses" view.
 * @param array $vars
 */
function elearning_preprocess_views_view__user_courses(&$vars) {
  $vars['classes_array'][] = 'grid-9';
  $vars['classes_array'][] = 'omega';
}

/**
 * Preprocess for node-type "Course" view.
 * @param array $vars
 * @param string $hook
 */
function elearning_preprocess_node_course(&$vars, $hook) {
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
    $field_name = field_view_field('user', $teacher[0]['user'], 'field_name', array('label' => 'hidden'));
    $field_surname = field_view_field('user', $teacher[0]['user'], 'field_surname', array('label' => 'hidden'));
    $vars['teacher_avatar'] = elearning_get_user_picture($teacher[0]['user'], '', 'user-profile');
    $vars['teacher_name'] = render($field_name);
    $vars['teacher_surname'] = render($field_surname);
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
 * @param string $hook
 */
function elearning_preprocess_node_question(&$vars, $hook) {
  $vars['userpoints_count'] = userpoints_get_current_points($vars['uid'], 'all');
  $vars['user_picture'] = elearning_get_user_picture($vars['uid'], 'question_author', 'node-question');
  $vars['created_formatted'] = t('%time ago', array('%time' => format_interval(REQUEST_TIME - $vars['created'], 1)));
}

/**
 * Preprocess for node-type "Open Question" view.
 * @param array $vars
 * @param string $hook
 */
function elearning_preprocess_node_open_question(&$vars, $hook) {
  $vars['display_submitted'] = FALSE;
  $vars['user_picture'] = elearning_get_user_picture($vars['uid'], 'question_author', 'node-question');
}


/**
 * Helper function, that checks if there is picture for the user
 * and generates HTML for it, otherwise it returns div with default class.
 * @param object $user
 * @param string $style_name
 * @param type $type
 * @return string HTML for the picture.
 */
function elearning_get_user_picture($user, $style_name, $type) {
  $user_picture = '<div class="' . $type. '-default-picture"></div>';  
  if (!is_object($user)) {
    $user = user_load($user);
  } else {
    $user_picture_test = theme('user_picture', array('account' => $user));
    return $user_picture_test == '' ? $user_picture : $user_picture_test;
  }
  if (!isset($user->picture->fid) || (!is_object($user->picture) && $user->picture = 0)) {
    return $user_picture;
  }
  if (is_numeric($user->picture)) {
    $user->picture = file_load($user->picture);
  }
  if (isset($user->picture->uri) && !empty($user->picture->uri)) {
    $filepath = $user->picture->uri;
    $user_picture = theme('image_style', array('style_name' => $style_name, 'path' => $filepath));
    return $user_picture;
  }
}

/**
 * Preprocess for HTML view.
 * @param array $vars
 * @param string $hook
 */
function elearning_preprocess_html(&$vars, $hook) {
  // hide page title if we are on "Course" node.
  $vars['show_title'] = isset($vars['page']['content']['content']['content']['system_main']['nodes'][1]['title_field']) ? TRUE : FALSE;
}

/**
 * Process variables for user-profile.tpl.php.
 * @param array $variables
 * @see user-profile.tpl.php
 */
function elearning_preprocess_user_profile(&$variables) {
  $account = $variables['elements']['#account'];
  $access = user_edit_access($account);
  $variables['access'] = $access;
  $variables['user_uid'] = $account->uid;
  $variables['user_name'] = $account->name;
  $variables['user_mail'] = $account->mail;
  $variables['user_picture'] = elearning_get_user_picture($account, '', 'user-profile');
  $field_name = field_view_field('user', $account, 'field_name', array('label' => 'hidden'));
  $field_surname = field_view_field('user', $account, 'field_surname', array('label' => 'hidden'));
  $field_birthday = field_view_field('user', $account, 'field_birthday', 'full');
  $field_phone = field_view_field('user', $account, 'field_phone_number');
  $variables['field_name'] = render($field_name);
  $variables['field_surname'] = render($field_surname);
  $variables['field_birthday'] = render($field_birthday);
  $variables['field_phone'] = render($field_phone);
  $variables['userpoints_count'] = userpoints_get_current_points($account->uid, 'all');
  if ($access) {
    $view = views_get_view('user_courses');
    $variables['user_courses_view'] = $view->preview('block', array($account->uid));
  }
}

/**
 * Preprocess for book-navigatoin.
 * @param array $vars
 */
function elearning_preprocess_book_navigation(&$vars) {
  $node = menu_get_object('node');
  if (in_array($node->type, array('lesson', 'open_question'))) {
    $vars['prev_title'] = t('Previous');
    $vars['next_title'] = t('Next');
  } 
}

/**
 * Implements hook preprocess_field
 * 
 * redirects preprocessing to function constracted from bundle and field names.
 * @see elearning_preprocess_field__lesson_field_video
 * @param type $vars
 */
function elearning_preprocess_field(&$vars) {
  $function = __FUNCTION__ . '__' . $vars['element']['#bundle'] . '_' . $vars['element']['#field_name'];
  if(function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocessing of field_video on lesson node.
 */
function elearning_preprocess_field__lesson_field_video(&$vars) {
  $vars['classes_array'][] = 'grid-12';
  $vars['classes_array'][] = 'alpha';
  $vars['classes_array'][] = 'omega';
}

/**
 * Preprocessing of field_video on course node.
 */
function elearning_preprocess_field__course_field_video(&$vars) {
  $vars['classes_array'][] = 'grid-8';
  $vars['classes_array'][] = 'alpha';
  $vars['classes_array'][] = 'omega';
}

/**
 * Implements hook_preprocess_block
 * Function redirects processing to functions that are buld of hook plus block id.
 * @see elearning_preprocess_block__answers_extra_question_answers
 */
function elearning_preprocess_block(&$vars) {
  if (isset($vars['elements'])) {
    $function = __FUNCTION__ . '__' . $vars['elements']['#block']->module . '_' . $vars['elements']['#block']->delta;
    // uncomment line bellow if you want to see the full id of needed block:
    // dvm ($vars['elements']['#block']->module . '_' . $vars['elements']['#block']->delta);
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Preprocessing for block Lesson Questions / Lesson Question Answers
 */
function elearning_preprocess_block__answers_extra_question_answers(&$vars) {
   $vars['attributes_array']['class'][] = 'grid-11 alpha omega';
}

/**
 * Preprocessing for flag for ctools modal support for abuse_content flag.
 */
function elearning_preprocess_flag(&$vars) {
  if (isset($vars['flag'])) {  
    $function = __FUNCTION__ . '__' . $vars['flag']->name;
    // uncomment line bellow if you want to see the full id of needed block:
    // dvm ($vars['elements']['#block']->module . '_' . $vars['elements']['#block']->delta);
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

function elearning_preprocess_flag__abuse_content(&$vars) {
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