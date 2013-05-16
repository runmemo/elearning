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
 * Helper function, that checks if there is picture for the user
 * and generates HTML for it, otherwise it returns div with default class.
 * @param object $user
 * @param string $style_name
 * @param type $type
 * @return string HTML for the picture.
 */
function elearning_get_user_picture($user, $style_name, $type) {
  $user_picture = '<div class="' . $type . '-default-picture"></div>';
  if (!is_object($user)) {
    $user = user_load($user);
  }
  else {
    $user_picture_test = theme('user_picture', array('account' => $user));
    return $user_picture_test == '' ? $user_picture : $user_picture_test;
  }
  if (!isset($user->picture->fid) || (!is_object($user->picture) && $user->picture = 0)) {
    return $user_picture;
  }
  if (is_numeric($user->picture)) {
    $user->picture = file_load($user->picture);
  }
  if (isset($user->picture->uri) && !empty($user->picture->uri)) {
    $filepath = $user->picture->uri;
    $user_picture = theme('image_style', array('style_name' => $style_name, 'path' => $filepath));
    return $user_picture;
  }
}

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
 * Process variables for user-profile.tpl.php.
 * @param array $variables
 * @see user-profile.tpl.php
 */
function elearning_preprocess_user_profile(&$variables) {
  $account = $variables['elements']['#account'];
  $access = user_edit_access($account);
  $variables['access'] = $access;
  $variables['user_uid'] = $account->uid;
  $variables['user_name'] = $account->name;
  $variables['user_mail'] = $account->mail;
  $variables['user_picture'] = elearning_get_user_picture($account, '', 'user-profile');
  $field_name = field_view_field('user', $account, 'field_name', array('label' => 'hidden'));
  $field_surname = field_view_field('user', $account, 'field_surname', array('label' => 'hidden'));
  $field_birthday = field_view_field('user', $account, 'field_birthday', 'full');
  $field_phone = field_view_field('user', $account, 'field_phone_number');
  $variables['field_name'] = render($field_name);
  $variables['field_surname'] = render($field_surname);
  $variables['field_birthday'] = render($field_birthday);
  $variables['field_phone'] = render($field_phone);
  $variables['userpoints_count'] = userpoints_get_current_points($account->uid, 'all');
  $view = views_get_view('user_courses');
  $variables['user_courses_view'] = $view->preview('block', array($account->uid));
}

/**
 * Preprocess for book-navigatoin.
 * @param array $vars
 */
function elearning_preprocess_book_navigation(&$vars) {
  $node = menu_get_object('node');
  if (in_array($node->type, array('lesson', 'open_question'))) {
    $vars['prev_title'] = t('Previous');
    $vars['next_title'] = t('Next');
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
  // delete system.menus.css
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
  // Remove fivestar.css file because we use our own widget.
  unset($css[drupal_get_path('module', 'fivestar') . '/css/fivestar.css']);
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
  $grades = course_process_grades($node);
  $grade_name = '';
  if (!empty($grades)) {
    foreach ($grades as $grade) {
      if ($grade['next_score'] != 0) {
        if ($credits >= $grade['score'] && $credits < $grade['next_score']) {
          $grade_name = $grade['desc'];
          break;
        }
      } else {
        if ($credits >= $grade['score']) {
          $grade_name = $grade['desc'];
        }
      }
    }
  }
  $variables['course']['grade_name'] = $grade_name;
  $variables['course']['grade_score'] = $credits . ' ' . t('(out of !count)', array('!count' => 100));;
  $variables['course']['teacher_name'] = $node_wrapper->field_teacher->field_name->raw();
  $variables['course']['teacher_surname'] = $node_wrapper->field_teacher->field_surname->raw();

  // Get logo of course provider.
  $logo_file = $node_wrapper->field_provider->field_logo->value() ? $node_wrapper->field_provider->field_logo->file->value() : '';
  $logo_image = !empty($logo_file) ? theme_image_style(array('style_name' => 'provider_logo', 'path' => $logo_file->uri, 'width' => $logo_file->image_dimensions['width'], 'height' => $logo_file->image_dimensions['height'])) : '';
  $variables['course']['provider_logo'] = !empty($logo_image) ? render($logo_image) : '';

  // Get signature from certificate's template.
  $template_wrapper = entity_metadata_wrapper('node', $template);
  if (isset($template_wrapper->field_signature)) {
    $signature_file = $template_wrapper->field_signature->value();
    $field_signature = !empty($signature_file) ? theme_image_style(array('style_name' => 'certificate_signature', 'path' => $signature_file['uri'], 'width' => $signature_file['image_dimensions']['width'], 'height' => $signature_file['image_dimensions']['height'])) : '';
    $variables['course']['teacher_signature'] = !empty($field_signature) ? render($field_signature) : '';
  }
}