<?php

/**
 * @file
 * Provides customisation of the output for eLearning theme.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */


/**
 * Preprocess for HTML view.
 * @param array $vars
 * @param string $hook
 */
function elearning_preprocess_html(&$vars, $hook) {
  // hide page title if we are on "Course" node.
  $vars['show_title'] = isset($vars['page']['content']['content']['content']['system_main']['nodes'][1]['title_field']) ? TRUE : FALSE;
}


/**
 * Preprocess for book-navigatoin.
 * @param array $vars
 */
function elearning_preprocess_book_navigation(&$vars) {
  $node = menu_get_object('node');
  $vars['prev_title'] = t('Previous');
  $vars['next_title'] = t('Next');

  $course_items = course_get_items($node);
  $current_item = $vars['book_link']['nid'];
  $course_first_item = array_shift(array_keys($course_items));

  // if we are on first course_item then do not show the prev_url.
  if ($course_first_item == $current_item) {
    $vars['prev_url'] = '';
  }

  // Make sure prev_url is in course_item (to avoid links to unit content_type).
  $prev_item = book_prev($node->book);
  $prev_nid = explode('/', $prev_item['link_path']);

  foreach($course_items as $key => $type) {
    if ($key == $current_item) {
      break;
    }
    $prev_course_item = $key;  
  }

  if ((!empty($prev_course_item)) && !empty($prev_nid[1]) && ($prev_course_item != $prev_nid[1])) {
    $vars['prev_url'] = url('node/'.$prev_course_item);
  }

  if (isset($node->outline_index)) {
    $vars['node_title'] = '<span class="outline-lesson-prefix">' . t('Lesson @i.', array('@i' => $node->outline_index)) . '</span>' . $node->title;  
  }
}

/**
 * Implements hook_css_alter().
 */
function elearning_css_alter(&$css) {
  // Get current themes path.
  $theme_path = drupal_get_path('theme', variable_get('theme_default', NULL));
  // Get formalize.css from subthemes css folder.
  if (array_key_exists('sites/all/themes/omega/omega/css/formalize.css', $css)) {
    $css['sites/all/themes/omega/omega/css/formalize.css']['data'] = $theme_path . '/css/formalize.css';
  }
      
  // Delete system.menus.css
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
  // Remove fivestar.css file because we use our own widget.
  unset($css[drupal_get_path('module', 'fivestar') . '/css/fivestar.css']);
  unset($css[drupal_get_path('module', 'ctools') . '/css/modal.css']);
  
}

/**
 * Implements hook_fivestar_widgets().
 */
function elearning_fivestar_widgets() {
  // Letting fivestar know about our custom Stars widget.
  $widgets = array(
    drupal_get_path('theme', 'elearning') . '/widgets/elearning_fivestar/elearning_fivestar_widget.css' => 'Elearning Stars',
  );
  return $widgets;
}

/**
 * Prepares variables for certificate-certificate.tpl.php
 */
function elearning_preprocess_certificate_certificate(&$variables) {
  global $base_url, $language;
  // Get basic information.
  $variables['language'] = $language->language;
  $variables['head'] = drupal_get_html_head();
  $variables['base_url'] = $base_url;
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $user = $variables['account'];
  $template = $variables['template'];
  $variables['url'] = $base_url . '/node/' . $node->nid . '/certificate';
  $variables['student_name'] = format_username($user);
  // Get course information.
  $variables['course']['title'] = $node_wrapper->title->raw();
  $credits = credit_calculate($node, $user);
  $grades = course_get_course_grades($node);
  $grade_name = '';
  if ($grades) {
    foreach ($grades as $score => $name) {
      if ($credits >= $score) {
        $grade_name = $name;
      }
    }
  }
  $variables['course']['grade_name'] = $grade_name;
  $variables['course']['grade_score'] = $credits . ' ' . t('(out of !count)', array('!count' => 100));;
  $variables['course']['teacher_name'] = $node_wrapper->field_teacher->field_first_name->raw();
  $variables['course']['teacher_surname'] = $node_wrapper->field_teacher->field_surname->raw();

  // Get logo of course provider.
  $logo_file = $node_wrapper->field_provider->field_logo->value() ? $node_wrapper->field_provider->field_logo->file->value() : '';
  $logo_image = !empty($logo_file) ? theme_image_style(array('style_name' => 'provider_logo_certificate', 'path' => $logo_file->uri, 'width' => $logo_file->image_dimensions['width'], 'height' => $logo_file->image_dimensions['height'])) : '';
  $variables['course']['provider_logo'] = !empty($logo_image) ? render($logo_image) : '';

  // Get signature from certificate's template.
  $template_wrapper = entity_metadata_wrapper('node', $template);
  if (isset($template_wrapper->field_signature)) {
    $signature_file = $template_wrapper->field_signature->value();
    $field_signature = !empty($signature_file) ? theme_image_style(array('style_name' => 'certificate_signature', 'path' => $signature_file['uri'], 'width' => $signature_file['image_dimensions']['width'], 'height' => $signature_file['image_dimensions']['height'])) : '';
    $variables['course']['teacher_signature'] = !empty($field_signature) ? render($field_signature) : '';
  }
}

function elearning_process_advanced_help_popup(&$variables) {
  
  // Get current themes path.
  $theme_path = drupal_get_path('theme', variable_get('theme_default', NULL));
  $css = $variables['css'];
  $advanced_help_css = drupal_get_path('module', 'advanced_help') . '/help-popup.css';
  if(array_key_exists($advanced_help_css, $css)) {
   unset($css[$advanced_help_css]);
   // http://localhost/coursehub.dev/themes/seven/style.css?mnmn0m
    $css = drupal_add_css($theme_path . '/css/help.css');
    
   
    
  }
  $variables['styles'] = drupal_get_css($css);
}

/**
 * Implements hook_preprocess_webform_form().
 */
function elearning_preprocess_webform_form(&$variables) {
  // Moving element titles to placeholders. 
  foreach ($variables['form']['submitted'] as $key => &$element) {
      if (!empty($element['#type']) && in_array($element['#type'], array('textfield', 'webform_email'))) {
          $element['#attributes']["placeholder"] = t($element["#title"]);
      }
  }
}
