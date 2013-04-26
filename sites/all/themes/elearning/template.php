<?php

/**
 * @file
 * Provides customisation of the output for eLearning theme.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

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
 * Process variables for comment.tpl.php.
 */
function elearning_preprocess_comment(&$vars) {
  $vars['submitted'] = t('!username - !time ago', array('!username' => $vars['author'], '!time' => format_interval(REQUEST_TIME - $vars['comment']->created, 1)));
}
