<?php
/**
 * @file
 *   Contains block hooks and functions that provide blocks content.
 */

/**
 * Implements hook_block_info().
 */
function course_block_info() {
  $blocks['registration_form'] = array(
    'info' => t('Course registration form'),
  );
  // Block for displaying book header
  $blocks['book_header'] = array(
    'info' => t('Course Header'),
  );
  // Block for displaying course item links
  $blocks['course_item_links'] = array(
    'info' => t('Course Links'),
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function course_block_view($delta = '') {
  // The $delta parameter tells us which block is being requested.
  switch ($delta) {
    case 'course_item_links':
      return course_item_links();
    case 'book_header':
      return course_header_block();
  }
}


/**
 * Return course item operation links
 */
function course_item_links() {
  $node = menu_get_object('node');
  if (!node_access('update', $node)) {
    return FALSE;
  }

  $block = array();
  $block['subject'] = '';
  $tabs = menu_local_tasks(0);
  $block['content'] = $tabs['tabs']['output'];
  return $block;
}

/**
 * Gets corresponding book for a node.
 * @return array An array, representing "Book Header" block.
 */
function course_header_block() {
  $block = array();
  $active_contexts = context_active_contexts();
   
  if (isset($active_contexts['course_pages'])) { // on course 
    $node = node_load(arg(1));
  }
  else if (isset($active_contexts['annoucement_page'])) {
    $annoucement_node = menu_get_object('node');
    $node = $annoucement_node->field_course[LANGUAGE_NONE][0]['entity'];
  }
  else {
    $node = menu_get_object('node');
  }

  if (!$node) {
    watchdog('block header', 'Block with header of the course was shown in the wrong place.', array(), WATCHDOG_WARNING);
    return $block;
  }

  $question_page = FALSE;
  $open_question_page = FALSE;
  $book = FALSE;

  if ($node->type === 'question') {
    $question_paths = field_get_items('node', $node, 'field_question_path');
    if ($question_paths) {
      $item_nid = str_ireplace('node/', '', $question_paths[0]['value']);
      $item = node_load($item_nid);
      if ($item) {
        $book = _node_get_book($item);
        $question_page = TRUE;
      }
      else { // node not found
        return $block;
      }
    }
    else { // question is not related to any page
      return $block;
    }
  }
  elseif ($node->type === 'open_question') {
    $open_question_page = TRUE;
    $book = _node_get_book($node);
  }
  else { // other content types
    $book = _node_get_book($node);
  }

  // Build the block title and contents
  if ($book) {
    $block['subject'] = '';
    $block['content'] = theme('course_header', array('book_link' => $book, 'question_page' => $question_page, 'open_question_page' => $open_question_page));
  }
  return $block;
}
