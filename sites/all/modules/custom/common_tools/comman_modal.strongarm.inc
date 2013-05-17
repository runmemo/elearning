<?php
/**
 * @file
 * common_tools.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function common_tools_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_added_selectors_array';
  $strongarm->value = array(
    0 => 'a.flag',
    1 => '.vud-link-down',
    2 => '.vud-link-up',
    3 => '.up-active',
    4 => 'a.comment-link',
    5 => '.oq-answer-form-submit',
  );
  $export['beautytips_added_selectors_array'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_added_selectors_string';
  $strongarm->value = 'a.flag, .vud-link-down, .vud-link-up, .up-active, a.comment-link, .oq-answer-form-submit';
  $export['beautytips_added_selectors_string'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_always_add';
  $strongarm->value = 1;
  $export['beautytips_always_add'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_custom_style';
  $strongarm->value = array(
    'fill' => '',
    'strokeWidth' => '',
    'strokeStyle' => '',
    'width' => '',
    'padding' => '',
    'cornerRadius' => '',
    'spikeGirth' => '',
    'spikeLength' => '',
    'shadowBlur' => '',
    'shadowColor' => '',
    'shadow' => 'default',
    'cssClass' => '',
  );
  $export['beautytips_custom_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_defaults';
  $strongarm->value = array(
    'fill' => '#fdfdfd',
    'padding' => 15,
    'strokeStyle' => 'transparent',
    'cornerRadius' => 0,
    'shadow' => TRUE,
    'shadowBlur' => 2,
    'cssStyles' => array(
      'color' => '#6A6A6A',
    ),
  );
  $export['beautytips_defaults'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_default_style';
  $strongarm->value = 'common-tooltip';
  $export['beautytips_default_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_drupal_help';
  $strongarm->value = 0;
  $export['beautytips_drupal_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_form_id';
  $strongarm->value = '';
  $export['beautytips_form_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_ltr';
  $strongarm->value = 0;
  $export['beautytips_ltr'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_position';
  $strongarm->value = 'right';
  $export['beautytips_position'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_show_form';
  $strongarm->value = 0;
  $export['beautytips_show_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'beautytips_text_input';
  $strongarm->value = 0;
  $export['beautytips_text_input'] = $strongarm;

  return $export;
}
