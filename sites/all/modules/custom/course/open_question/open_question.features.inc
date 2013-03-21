<?php
/**
 * @file
 * open_question.features.inc
 */

/**
 * Implements hook_node_info().
 */
function open_question_node_info() {
  $items = array(
    'open_question' => array(
      'name' => t('Open Question'),
      'base' => 'node_content',
      'description' => t('Represents open questions that can be part of the course and can be answered by a student.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'open_question_answer' => array(
      'name' => t('Open Question Answer'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
