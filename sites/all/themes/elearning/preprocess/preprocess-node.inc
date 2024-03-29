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
  // load students view
  $view = views_get_view('course_students'); 
  $vars['students_view'] = $view->preview('block', array($vars['nid']));
}

/**
 * Preprocess for node-type "Question" view.
 * @param array $vars
 */
function elearning_alpha_preprocess_node_question(&$vars) {
  $account = user_load($vars['uid']);

  $vars['user_picture'] = theme('user_picture', 
    array(
      'account' => $account, 
      'size' => 'tiny', 
      'show_points' => TRUE,
      'access' => FALSE,
    )
  );
  $vars['created_formatted'] = t('@time ago', array('@time' => format_interval(REQUEST_TIME - $vars['created'], 1)));

  if(node_access('update', $vars['node'])) {
    $vars['edit_link'] = l('', 'node/'.$vars['nid'].'/edit', array('attributes' => array('title' => t('Edit'), 'class' => 'edit-link')));
  }
}

/**
 * Preprocess for node-type "Open Question" view.
 * @param array $vars
 */
function elearning_alpha_preprocess_node_open_question(&$vars) {
  $vars['display_submitted'] = FALSE;
  $account = user_load($vars['uid']);
  $vars['user_picture'] = theme('user_picture', 
      array(
        'account' => $account, 
        'size' => 'tiny',
        'access' => FALSE,
      )
  );
  drupal_add_css(drupal_get_path('theme', 'elearning') . '/widgets/elearning_fivestar/elearning_fivestar_widget.css');
}

/**
 * Preprocess for node-type "Newsletter" view.
 * @param array $vars
 */
function elearning_alpha_preprocess_node_newsletter(&$vars) {
  $account = user_load($vars['uid']);

  $vars['user_picture'] = theme('user_picture', 
    array(
      'account' => $account, 
      'size' => 'tiny', 
      'show_points' => TRUE,
      'access' => FALSE,
    )
  );

  $name = field_view_field('user', $account, 'field_first_name', array('label' => 'hidden'));
  $surname = field_view_field('user', $account, 'field_surname', array('label' => 'hidden'));
  $vars['author'] = render($name).' '.render($surname);
  $vars['created_formatted'] = date('d/m/Y', $vars['created']);
}

function elearning_alpha_preprocess_node_webform(&$vars) {
  $webform_css = drupal_get_path('theme', 'elearning') . '/css/webform.css';
  drupal_add_css($webform_css, array('group' => CSS_THEME, 'type' => 'file'));
}