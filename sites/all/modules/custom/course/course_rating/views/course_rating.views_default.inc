<?php
/**
 * @file
 * course_rating.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function course_rating_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'courses_reviews';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Courses reviews';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Courses reviews';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['required'] = TRUE;
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => 'percent',
    'tag' => 'vote',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Course';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Votes: User */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'votingapi_vote';
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['label'] = 'Rating';
  $handler->display->display_options['fields']['value']['precision'] = '1';
  /* Field: Global: Course Rating Entity */
  $handler->display->display_options['fields']['course_rating_entity']['id'] = 'course_rating_entity';
  $handler->display->display_options['fields']['course_rating_entity']['table'] = 'views';
  $handler->display->display_options['fields']['course_rating_entity']['field'] = 'course_rating_entity';
  $handler->display->display_options['fields']['course_rating_entity']['label'] = 'Review';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Teacher (field_teacher) */
  $handler->display->display_options['arguments']['field_teacher_uid']['id'] = 'field_teacher_uid';
  $handler->display->display_options['arguments']['field_teacher_uid']['table'] = 'field_data_field_teacher';
  $handler->display->display_options['arguments']['field_teacher_uid']['field'] = 'field_teacher_uid';
  $handler->display->display_options['arguments']['field_teacher_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_teacher_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_teacher_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_teacher_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_teacher_uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_teacher_uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['field_teacher_uid']['validate_options']['restrict_roles'] = TRUE;
  $handler->display->display_options['arguments']['field_teacher_uid']['validate_options']['roles'] = array(
    4 => '4',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Courses Reviews';
  $export['courses_reviews'] = $view;

  return $export;
}
