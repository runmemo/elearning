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
  $vars['form_class_participate'] = drupal_get_form('course_registration_form');
  // load students view
  $view = views_get_view('course_students'); 
  $vars['students_view'] = $view->preview('block', array($vars['nid']));
}

/**
 * Preprocess for node-type "Question" view.
 * @param array $vars
 */
function elearning_alpha_preprocess_node_question(&$vars) {
  $vars['userpoints_count'] = userpoints_get_current_points($vars['uid'], 'all');
  $vars['user_picture'] = elearning_get_user_picture($vars['uid'], 'question_author', 'node-question');
  $vars['created_formatted'] = t('%time ago', array('%time' => format_interval(REQUEST_TIME - $vars['created'], 1)));
  $vars['subscribe_button'] =  render($vars['elements']['links']['flag']);
}

/**
 * Preprocess for node-type "Open Question" view.
 * @param array $vars
 */
function elearning_alpha_preprocess_node_open_question(&$vars) {
  $vars['display_submitted'] = FALSE;
  $vars['user_picture'] = elearning_get_user_picture($vars['uid'], 'question_author', 'node-question');
  drupal_add_css(drupal_get_path('theme', 'elearning') . '/widgets/elearning_fivestar/elearning_fivestar_widget.css');
}

