<?php

/**
 * @file
 * Rules integration for the Open Question module.
 */

/**
 * Implements hook_rules_action_info().
 */
function open_question_rules_action_info() {
  $items = array(
    'open_question_best_answer' => array(
      'label' => t('Update best answer to the question'),
      'base' => 'open_question_update_best_answer',
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

function open_question_update_best_answer($flag, $flagging_user, $flagged_node) {
  if ($flag->name == 'best_answer') {
    $question = answers_field_get_node_reference($flagged_node, 'field_answer_question');
    if ($question) {
      $old_answer = FALSE;
      if ($flag->is_flagged($flagged_node->nid, $flagging_user->uid)) {
        // remove the flag on the old best answer node (if there is one)
        open_question_remove_best_answer($question, $flagged_node->nid);
        // update the question
        $lang = field_language('node', $question, 'field_best_answer');
        $question->field_best_answer[$lang][0]['nid'] = $flagged_node->nid;
        node_save($question);

        // lock the question if appropriate
        if (variable_get('best_answer_lock_question_p', 0)) {
          answers_lock_question($question);
        }

        // set the flag on the new best answer node
        $lang = field_language('node', $flagged_node, 'field_best_answer_p');
        $flagged_node->field_best_answer_p[$lang][0]['value'] = 1;
        node_save($flagged_node);

        // if the rule module exist, trigger the rules event
        if (module_exists('rules')) {
          rules_invoke_event('best_answer_set', $question, $flagged_node);
        }
      } else {
        // remove the flag on the old best answer node (if there is one)
        open_question_remove_best_answer($question, $flagged_node->nid);
      }
      // provide 'hook_best_answer_set' to allow other modules to catch the event
      module_invoke_all('best_answer_set', $question, $flagged_node, $old_answer);
    }
  }
}
