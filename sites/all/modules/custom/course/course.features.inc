<?php

/**
 * @file
 * course.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function course_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
      return array("version" => "3");
  }
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
      return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
  
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function course_views_api() {
  return array(
    'api' => '3.0', 
    'path' =>  drupal_get_path('module', 'course') . '/views', 
  );
}

/**
 * Implements hook_node_info().
 */
function course_node_info() {
  $items = array(
    'course' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('Represent the full course.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'unit' => array(
      'name' => t('Unit'),
      'base' => 'node_content',
      'description' => t('Unit is a large section of course that consists of lessons, quizzes and other content. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'provider' => array(
      'name' => t('Provider'),
      'base' => 'node_content',
      'description' => t('Provider of course content, e.g. university or company.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'front_page_slide' => array(
      'name' => t('Front Page Slide'),
      'base' => 'node_content',
      'description' => t('Content type for slider on the home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_image_default_styles().
 */
function course_image_default_styles() {
  $styles = array();

  // Exported image style: course_students.
  $styles['course_students'] = array(
    'name' => 'course_students',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '51',
          'height' => '51',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: provider_logo.
  $styles['provider_logo'] = array(
    'name' => 'provider_logo',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '88',
          'height' => '88',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: teacher_picture.
  $styles['teacher_picture'] = array(
    'name' => 'teacher_picture',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '102',
          'height' => '108',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );
  
  // Exported image style: user_profile_picture.
  $styles['user_profile_picture'] = array(
    'name' => 'user_profile_picture',
    'effects' => array(
      4 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '107',
          'height' => '82',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
      5 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => '107',
          'height' => '82',
        ),
        'weight' => '2',
      ),
    ),
  );
  
  // Exported image style: course_home_picture.
  $styles['course_home_picture'] = array(
    'name' => 'course_home_picture',
    'effects' => array(
      6 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '408',
          'height' => '173',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: front_page_slide.
  $styles['front_page_slide'] = array(
    'name' => 'front_page_slide',
    'effects' => array(
      8 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '864',
          'height' => '394',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: provider_home_picture.
  $styles['provider_home_picture'] = array(
    'name' => 'provider_home_picture',
    'effects' => array(
      7 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '33',
          'height' => '33',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
