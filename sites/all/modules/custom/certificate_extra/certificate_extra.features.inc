<?php
/**
 * @file
 * certificate_extra.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function certificate_extra_image_default_styles() {
  $styles = array();

  // Exported image style: certificate_signature.
  $styles['certificate_signature'] = array(
    'name' => 'certificate_signature',
    'effects' => array(
      12 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 42,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: provider_logo_certificate.
  $styles['provider_logo_certificate'] = array(
    'name' => 'provider_logo_certificate',
    'effects' => array(
      11 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 79,
          'height' => 79,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
