<?php

/**
 * Process for page.
 * @param array $variables
 */
function elearning_alpha_process_page(&$variables) {
  if (isset($variables['node'])) {
    if ($variables['node']->type == 'webform') {
      $variables['title_hidden'] = FALSE; 
    }
  }
}
