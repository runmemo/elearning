<?php

/**
 * Implements hook_credit_result_info() from credit module.
 */
function open_question_credit_info() {
  $info = array();
  $info['oq'] = array(
    'bundle' => 'open_question',
    'result_callback' => 'open_question_result'
  );
  return $info;
}
 
/**
 * Gets result of open question completion for specific user.
 * 
 * @param object $node
 * @param object $account
 * 
 * @return
 *   Result of open question competion in a range from 0 to 1.
 */
function open_question_result($node, $account) {
 
  // Find answer of the user for this node.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'open_question_answer')
        ->propertyCondition('status', 1)
        ->propertyCondition('uid', $account->uid)
        ->fieldCondition('field_open_question', 'target_id', $node->nid, '=')
        ->range(0, 1);
  
  $result = $query->execute();
  
  if (isset($result['node'])) {
    $answers_nids = array_keys($result['node']);
    $answer_nid = $answers_nids[0];
    $stats =  open_question_get_feedback_stats($answer_nid); 
    if ($stats['count'] > 0) { // @todo give admin an option to chose number of feedbacks
      $result =  $stats['average'] / 5.0;
      return $result;
    }
  } 
  // User did not answer that open question yet 
  // or nobody provided user with feedback .
  return .0;
}
