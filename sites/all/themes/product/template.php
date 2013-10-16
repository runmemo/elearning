<?php

function product_preprocess_image(&$variables) {
  /* Make all images fluid */
  unset($variables['height']);
  unset($variables['attributes']['height']);
  unset($variables['height']);
  unset($variables['width']);
  $variables['width'] = '100%';
}