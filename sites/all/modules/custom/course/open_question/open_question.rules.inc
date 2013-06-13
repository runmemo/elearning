<?php

/**
 * Implementation of hook_rules_event_info()
 */
function open_question_rules_event_info() {
  return array(
    'open_question_answered' => array(
      'label' => t('Open question complete'),
      'module' => 'open_question',
      'group' => 'Course' ,
      'variables' => array(
        'answered_by' => array('type' => 'user', 'label' => t('User who answered the open question.')),
        'open_question' => array('type' => 'node', 'label' => t('The open question that was answered.')),
      ),
    ),
  );
}