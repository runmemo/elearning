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
  $element = $variables['element'];
  $depth = $element['#original_link']['depth'];
  $sub_menu = '';
  $is_book_menu = ($element['#original_link']['module'] === 'book');
  
  if ($is_book_menu && $depth == 2) {
    $output = '<h3>' . $element['#title'] . '</h3>';
  } 
  else { // not unit of the book
    $link  = l($element['#title'], $element['#href'], $element['#localized_options']);
    $output =  $link;
  }
    
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }  
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
