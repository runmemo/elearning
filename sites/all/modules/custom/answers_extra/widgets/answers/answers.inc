<?php

/**
 * @file
 * Answers up and down voting widget.
 */

/**
 * Plugin declaration.
 */
$plugin = array(
  'title' => t('Answers up and down widget'),
  'widget template' => 'widget',
  'alter template variables' => 'answers_widget_alter_template_vars',
);

/**
 * Alter template variables.
 */
function answers_widget_alter_template_vars($template_type, &$variables) {
  // Array with parameters to find all positive votes.
  $criteria = array(
    'entity_type' => $variables['type'],
    'entity_id' => $variables['entity_id'],
    'value_type' => 'points',
    'tag' => $variables['tag'],
    'function' => 'positives'
  );
  $positives = (int) votingapi_select_single_result_value($criteria);
  // Change criteria to find all negative votes.
  $criteria['function'] = 'negatives';
  $negatives = (int) votingapi_select_single_result_value($criteria);
  $points = $positives + $negatives;
  // Change class in order to fit any possible amount of characters.
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
}
