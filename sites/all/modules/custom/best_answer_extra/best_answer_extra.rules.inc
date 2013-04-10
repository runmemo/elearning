<?php

/**
 * @file
 * Rules integration for the Best Answer Extra module.
 */

/**
 * Implements hook_rules_action_info().
 */
function best_answer_extra_rules_action_info() {
  $items = array(
    'open_question_best_answer' => array(
      'label' => t('Update best answer to the question'),
      'base' => 'best_answer_extra_update_best_answer',
      'parameter' => array(
        'flag' => array(
          'type' => 'flag',
          'label' => t('Flag'),
          'flag_type' => 'node',
        ),
        'flagging_user' => array(
          'type' => 'user',
          'label' => t('User who flagged the content'),
          'description' => t('For non-global flags, this is the user who flagged the content. (For global flags, this argument is ignored.)'),
        ),
        'node' => array(
          'label' => t('Content flagged by user'),
          'type' => 'node',
        ),
      ),
      'group' => t('Node'),
    ),
  );
  return $items;
}

/**
 * Custom rules action for setting/removing best answer to/from the question.
 * @param object $flag
 * @param object $flagging_user
 * @param object $flagged_node
 */
function best_answer_extra_update_best_answer($flag, $flagging_user, $flagged_node) {
  if ($flag->name == 'best_answer') {
    $question = answers_field_get_node_reference($flagged_node, 'field_answer_question');
    $flagged = $flag->is_flagged($flagged_node->nid, $flagging_user->uid);
    if ($question) {
      $old_answer = FALSE;
      // remove the flag on the old best answer node (if there is one)
      $lang = field_language('node', $question, 'field_best_answer');
      if (isset($question->field_best_answer[$lang])) {
        $old_answer = answers_field_get_node_reference($question, 'field_best_answer');
        if ($old_answer) {
          $lang = field_language('node', $old_answer, 'field_best_answer_p');
          $old_answer->field_best_answer_p[$lang][0]['value'] = 0;
          node_save($old_answer);
          if ($old_answer->nid == $flagged_node->nid && !$flagged) {
            $question->field_best_answer = array();
          }
        } else {
          $question->field_best_answer = array();
        }
      }

      // update the question
      if ($flagged) {
        $question->field_best_answer[$lang][0]['nid'] = $flagged_node->nid;
      }
      node_save($question);

      // lock the question if appropriate
      if (variable_get('best_answer_lock_question_p', 0)) {
        answers_lock_question($question);
      }
      if ($flagged) {
        $lang = field_language('node', $flagged_node, 'field_best_answer_p');
        $flagged_node->field_best_answer_p[$lang][0]['value'] = 1;
        node_save($flagged_node);
      }
      // provide 'hook_best_answer_set' to allow other modules to catch the event
      if ($flagged) {
        module_invoke_all('best_answer_set', $question, $flagged_node, $old_answer);
      }
      // if the rule module exist, trigger the rules events
      if (module_exists('rules')) {
        if ($flagged) {
          rules_invoke_event('best_answer_set', $question, $flagged_node);
        }
        if (($old_answer && !$flagged && $old_answer->nid == $flagged_node->nid) || ($old_answer && $flagged && $old_answer->nid != $flagged_node->nid)) {
          rules_invoke_event('best_answer_unset', $question, $old_answer);
        }
      }
    }
  }
}
