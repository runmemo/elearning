<?php


/**
 * Implements hook_credit_info()
 */
function quiz_extra_credit_info() {
  $results = array();
  $results['quiz'] = array (
    'bundle' => 'quiz',
    // callback function must return value between 0 and 1.
    'result_callback' => 'quiz_extra_calculate_credit',
    
  );
  return $results;
}

/**
 * Calculates credit awared for completion of a quiz to a user
 * @see quiz_extra_credit_info()
 */
function quiz_extra_calculate_credit($quiz_node, $account) {
  if ($quiz_node->type !== 'quiz') {
    return .0;
  }
  $query = db_select('quiz_node_results', 'qr')->fields('qr', array('score'));
  $query->condition('uid', $account->uid)
      ->condition('nid', $quiz_node->nid)
      ->condition('is_evaluated', TRUE)
      ->orderBy('score','DESC')
      ->range(0, 1);
  $result = $query->execute()->fetch();
  if (!$result) {
    return .0;
  } 
  if($quiz_node->pass_rate > 0 && $result->score < $quiz_node->pass_rate) {
    // user did not pass this quiz so no credit is awarded
    return .0;
  }
  $percent = $result->score;  
  return $percent / 100;
}