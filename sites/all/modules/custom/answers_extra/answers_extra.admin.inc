<?php

/**
 * @file
 * Admin settings for Answers Extra module.
 */

/**
 * Menu callback; Permissions settings form.
 */
function answers_extra_permissions_form($form_state) {
  $form = array();

  $form['answers_edit_any_answer_points'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount of points required to get "edit any answer" access.'),
    '#default_value' => variable_get('answers_edit_any_answer_points', 0),
    '#size' => 60,
    '#maxlength' => 60,
    '#required' => TRUE,
    '#element_validate' => array('answers_extra_integer_validate'),
  );
  $form['answers_edit_any_question_points'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount of points required to get "edit any question" access.'),
    '#default_value' => variable_get('answers_edit_any_question_points', 0),
    '#size' => 60,
    '#maxlength' => 60,
    '#required' => TRUE,
    '#element_validate' => array('answers_extra_integer_validate'),
  );
  $form['answers_extra_rate_points'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount of points, which is necessary for rating content'),
    '#default_value' => variable_get('answers_extra_rate_points', 0),
    '#size' => 60,
    '#maxlength' => 60,
    '#required' => TRUE,
    '#element_validate' => array('answers_extra_integer_validate'),
  );

  return system_settings_form($form);
}


/**
 * Element validate handler to ensure an integer points value.
 */
function answers_extra_integer_validate($element, &$form_state) {
  if ($element['#value'] != '' && (!is_numeric($element['#value']) || intval($element['#value']) < 0)) {
    form_error($element, t('!name, must be a positive integer.', array('!name' => $element['#title'])));
  }
}
