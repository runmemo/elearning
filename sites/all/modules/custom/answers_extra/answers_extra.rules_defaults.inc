<?php

/**
 * @file
 * answers_extra.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration_alter().
 */

function answers_extra_default_rules_configuration_alter(&$configs) {
 
 //User votes up answer award 5 points to author.
  if (isset($configs['rules_user_votes_up_an_answer'])) {
    foreach($configs['rules_user_votes_up_an_answer']->actions() as $action) {
      if ($action->getElementName() == 'userpoints_action_grant_points') {
        $action->settings['points'] = 5;
      }
    }
  }

  //User votes up answer retracts 5 points from Author.
  if (isset($configs['rules_user_retracts_a_vote_up_on_an_answer'])) {
    foreach($configs['rules_user_retracts_a_vote_up_on_an_answer']->actions() as $action) {
      if ($action->getElementName() == 'userpoints_action_grant_points') {
        $action->settings['points'] = -5;
      }
    }
  }

  //unset all vote down rules for Q&A now.
  //@todo Bulat : Please define stories for Votes down actions on Q&A.
  if (isset($configs['rules_user_votes_down_a_question'])) {
    unset($configs['rules_user_votes_down_a_question']);
  }
  if (isset($configs['rules_user_retracts_a_vote_down_on_a_question'])) {
    unset($configs['rules_user_retracts_a_vote_down_on_a_question']);
  }
  if (isset($configs['rules_user_votes_down_an_answer'])) {
    unset($configs['rules_user_votes_down_an_answer']);
  }
  if (isset($configs['rules_user_retracts_a_vote_down_on_an_answer'])) {
    unset($configs['rules_user_retracts_a_vote_down_on_an_answer']);
  }

}
