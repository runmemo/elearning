<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

function elearning_menu_link(array $variables) {
  //print_nice($variables);
  $element = $variables['element'];
  $depth = $element['#original_link']['depth'];
  $sub_menu = '';
  if (isset($element['#original_link']['module']) 
        && $element['#original_link']['module'] == 'book') {
    $element['#attributes']['class'][] = 'level-' . $depth;
  }
    
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }  
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
