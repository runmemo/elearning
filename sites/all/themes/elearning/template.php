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

function elearning_preprocess_views_view__course_students(&$vars) {
  $vars['attributes_array']['class'][] = 'grid-4'; 
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
 * Preprocess for node-type "Question" view.
 * @param array $vars
 * @param string $hook
 */
function elearning_preprocess_node_question(&$vars, $hook) {
  // add custom js file for unselecting flagged nodes in a view.
  drupal_add_js(drupal_get_path('module', 'best_answer_extra') . '/best_answer_extra.js');
  $author = user_load($vars['uid']);
  $vars['userpoints_count'] = userpoints_get_current_points($author->uid);
  if (is_numeric($author->picture)) {
    $author->picture = file_load($author->picture);
  }
  if (isset($author->picture->uri) && !empty($author->picture->uri)) {
    $filepath = $author->picture->uri;
    $vars['user_picture'] = theme('image_style', array('style_name' => 'question_author', 'path' => $filepath));
  } else {
    $vars['user_picture'] = '<div class="node-question-default-picture"></div>';
  }
  $vars['created_formatted'] = t('%time ago', array('%time' => format_interval(REQUEST_TIME - $vars['created'], 1)));
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
  drupal_add_js(drupal_get_path('theme', 'elearning') . '/js/elearning.js');
  $account = $variables['elements']['#account'];
  $variables['user_uid'] = $account->uid;
  $variables['user_name'] = $account->name;
  $variables['user_mail'] = $account->mail;
  $variables['user_picture'] = theme('user_picture', array('account' => $account));
  if (!isset($variables['user_picture']) || $variables['user_picture'] == '') {
    $variables['user_picture'] = '<div class="user-profile-default-picture"></div>';
  }
  $field_name = field_view_field('user', $account, 'field_name', array('label' => 'hidden'));
  $field_surname = field_view_field('user', $account, 'field_surname', array('label' => 'hidden'));
  $field_birthday = field_view_field('user', $account, 'field_birthday', 'full');
  $field_phone = field_view_field('user', $account, 'field_phone_number');
  $variables['field_name'] = render($field_name);
  $variables['field_surname'] = render($field_surname);
  $variables['field_birthday'] = render($field_birthday);
  $variables['field_phone'] = render($field_phone);
  $variables['userpoints_count'] = userpoints_get_current_points();
  $view = views_get_view('user_courses');
  $variables['user_courses_view'] = $view->preview('block', array($account->uid));
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
  $function = 'theme_preprocess_field__' . $vars['element']['#bundle'] . '_' . $vars['element']['#field_name'];
  if(function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocessing of field_video on lesson node.
 */
function elearning_preprocess_field__lesson_field_video(&$vars) {
  $vars['classes_array'][] = 'grid-9';
}

/**
 * Implements hook_preprocess_block
 * Function redirects processing to functions that are buld of hook plus block id.
 * @see elearning_preprocess_block__lesson_questions_lesson_question_answers
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
function elearning_preprocess_block__lesson_questions_lesson_question_answers(&$vars) {
   $vars['attributes_array']['class'][] = 'grid-11';
}
