<?php
/**
 * @file
 * course.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function course_views_default_views() {
  $export = array();

  // Course Teachers
  $view = new view();
  $view->name = 'course_teachers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Course Teachers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course Teachers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: User: Teacher (field_teacher) - reverse */
  $handler->display->display_options['relationships']['reverse_field_teacher_node']['id'] = 'reverse_field_teacher_node';
  $handler->display->display_options['relationships']['reverse_field_teacher_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_teacher_node']['field'] = 'reverse_field_teacher_node';
  $handler->display->display_options['relationships']['reverse_field_teacher_node']['required'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_teacher_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_description'] = 'Teachers';
  $export['course_teachers'] = $view;

  $view = new view();
  $view->name = 'course_students';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'registration';
  $view->human_name = 'Course Students';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Students';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['fill_single_line'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['label'] = 'Number of students';
  $handler->display->display_options['header']['php']['php_output'] = 
    '<p>
      <?php 
        $count_wrap = \'<span class="right">@count</span>\';
        print format_plural($view->total_rows, \'Student \' . $count_wrap, \'Students \' .$count_wrap);
      ?>
    </p>';
      
  /* Relationship: Registration: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'registration';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Registration: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'registration';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<div class="small-avatar"></div>';
  $handler->display->display_options['fields']['picture']['image_style'] = 'user_profile_picture';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '>';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Course Students';
  $export['course_students'] = $view;
  
  $view = new view();
  $view->name = 'user_courses';
  $view->description = 'View for displaying user\'s courses with progress-bars';
  $view->tag = 'default';
  $view->base_table = 'registration';
  $view->human_name = 'User Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My courses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'My courses';
  $handler->display->display_options['header']['area']['format'] = 'plain_text';
  /* Relationship: Registration: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'registration';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Registration: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'registration';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Registration: Cancelled */
  $handler->display->display_options['filters']['cancelled']['id'] = 'cancelled';
  $handler->display->display_options['filters']['cancelled']['table'] = 'registration';
  $handler->display->display_options['filters']['cancelled']['field'] = 'cancelled';
  $handler->display->display_options['filters']['cancelled']['value']['value'] = '0';
  
  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'User profile My courses block';
  $export['user_courses'] = $view;
  
  $view = new view();
  $view->name = 'courses';
  $view->description = 'Shows a courses page';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Courses';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_column_class';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_discipline' => 'field_discipline',
    'field_teacher' => 'field_teacher',
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'There is no result for the searched item,';
  /* Relationship: Content: Teacher (field_teacher) */
  $handler->display->display_options['relationships']['field_teacher_uid']['id'] = 'field_teacher_uid';
  $handler->display->display_options['relationships']['field_teacher_uid']['table'] = 'field_data_field_teacher';
  $handler->display->display_options['relationships']['field_teacher_uid']['field'] = 'field_teacher_uid';
  $handler->display->display_options['relationships']['field_teacher_uid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_teacher_uid']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_provider_target_id']['id'] = 'field_provider_target_id';
  $handler->display->display_options['relationships']['field_provider_target_id']['table'] = 'field_data_field_provider';
  $handler->display->display_options['relationships']['field_provider_target_id']['field'] = 'field_provider_target_id';
  /* Relationship: Content: Discipline (field_discipline) */
  $handler->display->display_options['relationships']['field_discipline_tid']['id'] = 'field_discipline_tid';
  $handler->display->display_options['relationships']['field_discipline_tid']['table'] = 'field_data_field_discipline';
  $handler->display->display_options['relationships']['field_discipline_tid']['field'] = 'field_discipline_tid';
  $handler->display->display_options['relationships']['field_discipline_tid']['label'] = 'field_discipline';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'home-courses-title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'home-courses-image';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'course_home_picture',
    'image_link' => '',
  );
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['relationship'] = 'field_provider_target_id';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['element_wrapper_class'] = 'home-courses-provider-logo';
  $handler->display->display_options['fields']['field_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => 'provider_home_picture',
    'image_link' => '',
  );
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_teacher_uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['type'] = 'text_plain';
  /* Field: User: Surname */
  $handler->display->display_options['fields']['field_surname']['id'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['table'] = 'field_data_field_surname';
  $handler->display->display_options['fields']['field_surname']['field'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['relationship'] = 'field_teacher_uid';
  $handler->display->display_options['fields']['field_surname']['label'] = '';
  $handler->display->display_options['fields']['field_surname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_surname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_surname']['type'] = 'text_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Lector:';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_first_name] [field_surname]';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'home-courses-teacher';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Provider */
  $handler->display->display_options['fields']['field_provider']['id'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['table'] = 'field_data_field_provider';
  $handler->display->display_options['fields']['field_provider']['field'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['label'] = '';
  $handler->display->display_options['fields']['field_provider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_provider']['element_wrapper_class'] = 'home-courses-provider';
  $handler->display->display_options['fields']['field_provider']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_provider']['settings'] = array(
    'link' => 0,
  );
  /* Field: Global: Course Rating */
  $handler->display->display_options['fields']['course_rating']['id'] = 'course_rating';
  $handler->display->display_options['fields']['course_rating']['table'] = 'views';
  $handler->display->display_options['fields']['course_rating']['field'] = 'course_rating';
  $handler->display->display_options['fields']['course_rating']['label'] = '';
  $handler->display->display_options['fields']['course_rating']['element_label_colon'] = FALSE;
  /* Field: Content: Content */
  $handler->display->display_options['fields']['field_course_content']['id'] = 'field_course_content';
  $handler->display->display_options['fields']['field_course_content']['table'] = 'field_data_field_course_content';
  $handler->display->display_options['fields']['field_course_content']['field'] = 'field_course_content';
  $handler->display->display_options['fields']['field_course_content']['label'] = '';
  $handler->display->display_options['fields']['field_course_content']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_content']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_discipline_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['combine']['group_info']['label'] = 'Combine fields filter';
  $handler->display->display_options['filters']['combine']['group_info']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['combine']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_course_content' => 'field_course_content',
    'name' => 'name',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'courses';
  $export['courses'] = $view;


  $view = new view();
  $view->name = 'user_teaches_courses'; 
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'User teaches courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'I teach';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'I teach';
  $handler->display->display_options['header']['area']['format'] = 'plain_text';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  $handler->display->display_options['arguments']['field_teacher_uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['field_teacher_uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['field_teacher_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_teacher_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_teacher_uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['user_teaches_courses'] = array(
    t('Master'),
    t('I teach'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Block'),
  );
  $export['user_teaches_courses'] = $view;
    
  return $export;
}
