<?php
/**
 * @file
 * front_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function front_page_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function front_page_node_info() {
  $items = array(
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
function front_page_image_default_styles() {
  $styles = array();

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
          'width' => 408,
          'height' => 173,
        ),
        'weight' => 1,
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
          'width' => 864,
          'height' => 394,
        ),
        'weight' => 1,
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
          'width' => 33,
          'height' => 33,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
