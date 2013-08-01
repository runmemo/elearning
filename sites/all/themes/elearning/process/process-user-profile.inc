<?php

/**
 * Preprocess variables for user-profile.tpl.php.
 */
function elearning_alpha_process_user_profile(&$variables) {
  $account = $variables['elements']['#account'];
  $access = user_edit_access($account);
  $variables['access'] = $access;
  $variables['userpoints_count'] = userpoints_get_current_points($account->uid, 'all');
  // User courses
  $view = views_get_view('user_courses');
  $variables['user_courses_view'] = $view->preview('block', array($account->uid));
  // User teaches view
  if (user_access('edit own course content')) {
    $view = views_get_view('user_teaches_courses');
    $view->execute();
    if (count($view->result) == 0) { 
      $variables['user_teaches_courses'] = NULL;
    }
    else {
      $variables['user_teaches_courses'] = $view->preview('block', array($account->uid));
    }   
  }
  else {
    $variables['user_teaches_courses'] = NULL;
  }
}
