<?php

/**
 * Preprocess variables for user-profile.tpl.php.
 */
function elearning_alpha_process_user_profile(&$variables) {
  $account = $variables['elements']['#account'];
  $access = user_edit_access($account);
  $variables['access'] = $access;
  $variables['userpoints_count'] = userpoints_get_current_points($account->uid, 'all');
  $view = views_get_view('user_courses');
  $variables['user_courses_view'] = $view->preview('block', array($account->uid));
  $view = views_get_view('user_teaches_courses');
  $variables['user_teaches_courses'] = $view->preview('block', array($account->uid));
}
