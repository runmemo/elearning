<?php

/**
 * Processes variables for book_header.
 *
 * The $variables array contains the following elements:
 * - book_link
 */
function template_preprocess_course_header(&$vars) {
  $book_link = $vars['book_link'];
  $course_node = node_load($book_link['bid']);
  $node = menu_get_object('node');
  $active_contexts = context_active_contexts();
  $vars['follow_link'] = '';

  // course title
  if (isset($active_contexts['course_pages']) || isset($active_contexts['annoucement_page'])) {
    $attributes = array(
      'class' => 'course-title-link',
      'title' => t('Back to class.')
    );
    $course_link = course_last_visited_node($course_node->nid);
    $vars['course_title'] = l($course_node->title, 'node/'.$course_link, array('attributes' => $attributes));
    if(arg(2) == 'blog') {
      $vars['follow_link'] =  flag_create_link('follow_content', $course_node->nid);
    }
  }
  else {
    $vars['course_title'] = $course_node->title;
  }

  // provider logo and name
  $vars['provider_logo'] = '<div class="provider-logo-default"></div>';

  $provider = field_get_items('node', $course_node, 'field_provider');
  if ($provider) {
    $provider_node = node_load($provider[0]['target_id']);
    $provider_logo = field_view_field('node', $provider_node, 'field_logo', array('label' => 'hidden', 'settings' =>
       array('image_style' => 'provider_logo')));
    $vars['provider_logo'] = render($provider_logo);
  }
  // teacher logo and name
  $teacher = field_get_items('node', $course_node, 'field_teacher');
  if ($teacher) {
    $teacher_account = user_load($teacher[0]['uid']);
    $name = field_view_field('user', $teacher_account, 'field_first_name', array('label' => 'hidden'));
    $surname = field_view_field('user', $teacher_account, 'field_surname', array('label' => 'hidden'));
    $vars['teacher_name'] = render($name);
    $vars['teacher_surname'] = render($surname);
  }
  else {
    // provide default values for teacher name variables:
    $vars['teacher_name'] = '';
    $vars['teacher_surname'] = '';
  }

  if ($vars['question_page'] == TRUE) {
    $vars['return_link'] = l(t('Return to class'), $book_link['href'], array('attributes' => array('class' => array('node-question-return-link'))));
  }
  else if (isset($active_contexts['annoucement_page'])) {
    $vars['return_link'] = l(t('Return to annoucements'), 'node/'.$course_node->nid.'/blog', array('attributes' => array('class' => array('node-question-return-link'))));
  }
  else {
    $vars['return_link'] = '';
  }


  if((($book_link['nid'] !== $book_link['bid']) && isset($node->book)) || isset($active_contexts['course_pages'])) {
    $items = array(
      l(t('Blog'), 'node/'.$course_node->nid.'/blog', array('attributes' => array('class' => array('course-blog-link')))),
      l(t('Forum'), 'course/'.$course_node->nid.'/questions', array('attributes' => array('class' => array('course-forum-link')))),
    );
    $variables = array(
      'items' => $items,
      'attributes' => array('class' => array('course-links')),
    );
    $vars['course_links'] = theme('item_list', $variables);
  }
  else {
    $vars['course_links'] = '';
  }
}

/**
 * Preprocessor function for modal form for leaving the course
 */
function template_preprocess_course_leave_modal(&$vars) {
  // confirmation text
  $vars['disclaimer'] = 
      t('Are you sure you wants to leave this course : @course_title?', 
      array('@course_title' => $vars['course']->title));
  // buttons
  $vars['leave_button'] = ctools_ajax_text_button(t('Yes, leave'), "course-exit-action/nojs/exit/{$vars['uid']}/{$vars['course']->nid}", t('Yes'));
  $vars['cancel_button'] = ctools_ajax_text_button(t('Cancel'), "course-exit-action/nojs/cancel/{$vars['uid']}/{$vars['course']->nid}", t('Cancel'));
}
