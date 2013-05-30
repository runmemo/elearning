<?php

/**
 * @file
 * Elearning Up Down Widget.
 */
/**
 * Plugin decleration.
 */
$plugin = array(
  'title' => t('Elearning Up and down'),
  'widget template' => 'widget',
  'alter template variables' => 'elearning_widget_alter_template_vars',
);

/**
 * Alter template variables.
 */
function elearning_widget_alter_template_vars($template_type, &$variables) {
  global $user;
  // array with parameters to find all positive votes
  $criteria = array(
    'entity_type' => $variables['type'],
    'entity_id' => $variables['entity_id'],
    'value_type' => 'points',
    'tag' => $variables['tag'],
    'function' => 'positives'
  );
  $positives = (int) votingapi_select_single_result_value($criteria);
  // change criteria to find all negative votes
  $criteria['function'] = 'negatives';
  $negatives = (int) votingapi_select_single_result_value($criteria);
  $points = $positives + $negatives;
  //change class in order to fit any possible amount of characters.
  if ($points >= 0 && $points < 10) {
    $current_class = 'current-default';
  } elseif ($points < 0 && $points > -10) {
    $current_class = 'current-negative';
  } elseif ($points >= 10 && $points < 100) {
    $current_class = 'current-medium';
  } elseif ($points >= 100 && $points < 1000) {
    $current_class = 'current-wide';
  } elseif ($points <= -10 && $points > -100) {
    $current_class = 'current-negative-wide';
  } else {
    $current_class = 'current-small';
  }
  $variables['current_class'] = $current_class;
  $variables['current_points'] = $points;
  // check, whether the node belongs to the current user
  // and define access to the links and message for tooltips
  $node = isset($variables['entity_id']) ? node_load($variables['entity_id']) : FALSE;
  $variables['vote_acess'] = (!$node || ($node && $node->uid == $user->uid)) ? FALSE : TRUE;
  if ($variables['vote_acess']) {
    $variables['title_text_up'] = $variables['class_up'] == 'up-active' ? t('Reset your vote') : t('Vote up!');
    $variables['title_text_down'] = $variables['class_down'] == 'down-active' ? t('Reset your vote') : t('Vote down!');
  } else {
    $variables['title_text_up'] = t('You cannot vote up your own !content_type', array('!content_type' => $node ? $node->type : t('content')));
    $variables['title_text_down'] = t('You cannot vote down your own !content_type', array('!content_type' => $node ? $node->type : t('content')));
  }

  // check, whether the current user has minimum required points and its not the node author.
  if(!user_has_min_voting_points() && ($node->uid <> $user->uid)) {
    $variables['vote_acess'] = FALSE;
    $variables['title_text_up'] = t('You need to have !points points to be able to vote up this !content_type', array('!points' => QA_RATE_POINTS, '!content_type' => $node ? $node->type : t('content')));
    $variables['title_text_down'] = t('You need to have !points points to be able to vote down this !content_type', array('!points' => QA_RATE_POINTS, '!content_type' => $node ? $node->type : t('content')));    
  }
}
