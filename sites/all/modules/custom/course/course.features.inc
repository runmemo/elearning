<?php

/**
 * @file
 * course.features.inc
 */

/**
 * Implements hook_views_api().
 */
function course_views_api() {
  return array(
    'api' => '3.0', 
    'path' =>  drupal_get_path('module', 'course') . '/views', 
  );
}

/**
 * Implements hook_node_info().
 */
function course_node_info() {
  $items = array(
    'course' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('Represent the full course.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'lesson' => array(
      'name' => t('Lesson'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'unit' => array(
      'name' => t('Unit'),
      'base' => 'node_content',
      'description' => t('Unit is a large section of course that consists of lessons, quizzes and other content. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'provider' => array(
      'name' => t('Provider'),
      'base' => 'node_content',
      'description' => t('Provider of course content, e.g. university or company.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}