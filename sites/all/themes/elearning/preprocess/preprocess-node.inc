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
}


function elearning_alpha_preprocess_node_certificate(&$vars) {
  if (($vars['elements']['#view_mode'] == 'print') 
      && isset($vars['elements']['#print_format'])) {
     // $vars['node_title_custom'] = $vars['node']->title;
  }
}

function elearning_alpha_preprocess_node_answer(&$vars) {
  if ($vars['page']) {
    $q_nid = $vars['field_answer_question'][0]['nid'];
    drupal_goto("node/{$q_nid}", array('fragment' => "answer-{$vars['nid']}"), '302');
  }
}

function elearning_alpha_preprocess_node_open_question_answer(&$vars) {
  if ($vars['page']) {
    $oq_nid = $vars['field_open_question'][0]['target_id'];
    //@todo barinder : Find a way to open 2nd quicktab by default.
    drupal_goto("node/{$oq_nid}", array('fragment' => "answer-{$vars['nid']}"), '302');
  }
}

function elearning_alpha_preprocess_node_open_question_feedback(&$vars) {
  if ($vars['page']) {
    $oqa_nid = $vars['field_open_question_answer'][0]['target_id'];
    //@todo barinder : Find a way to open 2nd quicktab by default.
    drupal_goto("node/{$oqa_nid}", array(), '302');
  }
}
