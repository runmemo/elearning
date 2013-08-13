<?php


/**
 * Implements hook_block_info().
 */
function open_question_block_info() {
  $blocks['oq_answer_form_block'] = array(
    'info' => t('OQ Answer Form Block'),
  );
  $blocks['oq_other_answers_block'] = array(
    'info' => t('OQ Answers Review List'),
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function open_question_block_view($delta = '') {
  $block = array();
  if (!in_array($delta, array('oq_answer_form_block','oq_other_answers_block'))) {
    return $block;
  }
  $question = menu_get_object('node');
  if (!$question || $question->type != 'open_question') {
    watchdog('open question', 
        'Open question block %delta is displayed on non question page: %path', 
       array('%path' => current_path(), '%delta' => $delta), WATCHDOG_WARNING);
    return;
  }
  $answered = open_question_is_answered($question->nid);

  switch ($delta) {
    
    case 'oq_answer_form_block':
      $block['subject'] = '';

      if (!node_access('create', 'open_question_answer')) {
        // User does not have rights to see the form.
        $block['content'] = array (
          '#type' => 'markup',
          '#prefix' => '<p class="oq-review-no-access no-access-message">',
          '#suffix' => '</p>',
          '#markup' => t('You need complete registration to answer this question.'),
        );
        return $block;     
      }
      // Add answer form.
      $block['content']['answer_form']= drupal_get_form('open_question_answer_form', $answered);
      
      // Get view with feedbacks. 
      if ($answered) {
        $block['content']['view'] = open_question_feedbacks_view($answered); 
      }
      else {
        // User did not answer the question, so there are no feedbacks.
        return $block;
      }
    
      break;
      
    case 'oq_other_answers_block':
      $block['subject'] = '';
     
      if ($answered) {
        $block['content'] = open_question_review_list_view($question->nid);
      }
      else {
        $block['content']['message'] = array(
         '#type' => 'markup',
         '#prefix' => '<p class="oq-review-no-access no-access-message">',
         '#suffix' => '</p>',
         '#markup' => t('You need to answer question before you can review answers of other students.'),
        );
      }
    break;
  }
  return $block;
}


/**
 * Gets nid of answer by user to open question.
 * 
 * @param integer $nid
 * @param integer $uid
 * 
 * @return integer
 *   Nid of user's answer to open question
 */
function open_question_is_answered($nid, $uid = NULL) {
  if (is_null($uid)) {
    global $user;
    $uid = $user->uid;
  }
  // Count number of answers given by user.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'open_question_answer')
      ->propertyCondition('status', 1)
      ->propertyCondition('uid', $uid)
      ->fieldCondition('field_open_question', 'target_id', $nid)
      ->range(0, 1); // This is just to improve db performance.

  $result = $query->execute();

  foreach ($result as $entity_type => $entities) {
    foreach ($entities as $entity_id => $entity) {
      return $entity_id;
    }
  }

  return FALSE;
}

/**
 * Generates embedded view with feedbacks, along with stas for results.
 * 
 * @param integer $oq_nid
 *   Open question answer nid.
 * 
 * @return 
 *   array with HTML for a view with feedbacks and count.
 */
function open_question_feedbacks_view($oqa_nid) {
  $view = views_get_view('oqa_feedbacks');
  $view->set_arguments(array($oqa_nid));
  $output = array();
  
  $feedbacks_view_preview = $view->preview('block');
  
  // Markup for the view.
  $output['reviews'] = array(
    '#type' => 'markup',
    '#markup' => $feedbacks_view_preview,
    '#weight' => 1,
  );
  
  // Container for feedback summary.
  $output['summary'] = array (
    '#weight' => 0,
    '#prefix' => '<div class="oq-answer-feedback-summary">',
    '#suffix' => '</div>',
  );
  
  // Markup with summary of reviews.
  $output['summary']['reviews_count'] = array(
    '#prefix' => '<div class="oq-answer-view-description">',
    '#suffix' => '</div>',
    '#markup' => t('No reviews'),
  );

  if ($view->total_rows > 0) {
    $output['summary']['reviews_count']['#markup'] = format_plural($view->total_rows, '1 review:', '@count reviews:');
  }
  // Get feedback stats.
  $stats = open_question_get_feedback_stats($oqa_nid);
  if ($stats['count']) {
    $output['summary']['rating'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="oq-answer-rating">',
      '#suffix' => '</div>',
      '#markup' =>
      t('Your average score: !average', array('!average' => $stats['average']))
      . '<span class="answer-feedbacks-count"> ' . t('(out of !count)', array('!count' => $stats['count'])) . '</span>',
    );
  }
 
  return $output;
}
