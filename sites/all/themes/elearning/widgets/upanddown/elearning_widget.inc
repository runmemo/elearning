<?php

/**
 * @file
 * Up Down Widget.
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
  $criteria = array(
    'entity_type' => $variables['type'],
    'entity_id' => $variables['entity_id'],
    'value_type' => 'points',
    'tag' => $variables['tag'],
    'function' => 'positives'
  );
  $positives = (int) votingapi_select_single_result_value($criteria);
  $variables['up_points'] = $positives;

  $criteria = array(
    'entity_type' => $variables['type'],
    'entity_id' => $variables['entity_id'],
    'value_type' => 'points',
    'tag' => $variables['tag'],
    'function' => 'negatives'
  );
  $negatives = (int) votingapi_select_single_result_value($criteria);
  $variables['down_points'] = $negatives;
  $variables['show_reset'] = FALSE;
  if (!$variables['show_up_as_link']) {
    $points = $positives;
    $variables['current_class'] = 'current-default';
  } elseif (!$variables['show_down_as_link']) {
    $points = $negatives;
    $variables['current_class'] = 'current-negative';
  } else {
    $points = 0;
    $variables['current_class'] = 'current-default';
  }
  $variables['current_points'] = $points;
}
