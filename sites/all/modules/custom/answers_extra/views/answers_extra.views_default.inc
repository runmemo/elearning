<?php

/**
 * @file
 * answers_expra.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function answers_extra_views_default_views() {

  $export = array();
  $view = new view();
  $view->name = 'answers_to_a_question_extra';
  $view->description = 'Answers to the current question';
  $view->tag = 'Answers';
  $view->base_table = 'node';
  $view->human_name = 'Question Answers (Extra)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Answers';
  $handler->display->display_options['css_class'] = 'view-question-answers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = '<em>No answers yet</em>';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Flags: best_answer */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'best_answer';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Rating Widget */
  $handler->display->display_options['fields']['field_rating_widget']['id'] = 'field_rating_widget';
  $handler->display->display_options['fields']['field_rating_widget']['table'] = 'field_data_field_rating_widget';
  $handler->display->display_options['fields']['field_rating_widget']['field'] = 'field_rating_widget';
  $handler->display->display_options['fields']['field_rating_widget']['label'] = '';
  $handler->display->display_options['fields']['field_rating_widget']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_rating_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rating_widget']['click_sort_column'] = 'vud_widget';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['empty'] = '<div id="[nid]"></div>';
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created']['custom_date_format'] = '1';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Inline Comments */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  /* Field: Field Grouping */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Field Grouping';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 
    '<div class="views-answer-widgets">
         <div class="views-field-field-rating-widget">[field_rating_widget]</div>
         <div class="views-field-ops">[ops]</div>
       </div>
       <div class="views-answer-body">
         <div class="views-field-body">[body]</div>
         <div class="node-supplementary-wrapper"> 
           <div class="views-field-created">[created]</div>
           <div class="views-field-name">[name]</div>
           <div class="views-field-comment-count">[comment_count]</div>
         </div>
       </div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Best Answer (field_best_answer_p) */
  $handler->display->display_options['sorts']['field_best_answer_p_value']['id'] = 'field_best_answer_p_value';
  $handler->display->display_options['sorts']['field_best_answer_p_value']['table'] = 'field_data_field_best_answer_p';
  $handler->display->display_options['sorts']['field_best_answer_p_value']['field'] = 'field_best_answer_p_value';
  $handler->display->display_options['sorts']['field_best_answer_p_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Question (field_answer_question) */
  $handler->display->display_options['arguments']['field_answer_question_nid']['id'] = 'field_answer_question_nid';
  $handler->display->display_options['arguments']['field_answer_question_nid']['table'] = 'field_data_field_answer_question';
  $handler->display->display_options['arguments']['field_answer_question_nid']['field'] = 'field_answer_question_nid';
  $handler->display->display_options['arguments']['field_answer_question_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_answer_question_nid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_answer_question_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_answer_question_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_answer_question_nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_answer_question_nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_answer_question_nid']['validate_options']['types'] = array(
    'question' => 'question',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'answer' => 'answer',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_answers');
  $export[$view->name] = $view;

  return $export;
}