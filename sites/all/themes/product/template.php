<?php


function product_preprocess_image(&$variables) {
// print_nice($variables);
  unset ($variables['height']);
  unset($variables['attributes']['height']);
    unset ($variables['height']);
  unset($variables['width']);
  $variables['width'] = '100%';
}



function product_preprocess_webform_form(&$variables) {
  // Moving element titles to placeholders. 
  foreach ($variables['form']['submitted'] as $key => &$element) {
      if (!empty($element['#type']) && in_array($element['#type'], array('textfield', 'webform_email'))) {
          $element['#attributes']["placeholder"] = t($element["#title"]);
      }
  }
}
