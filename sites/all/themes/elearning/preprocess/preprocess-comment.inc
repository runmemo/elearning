<?php

/**
 * Process variables for comment.tpl.php.
 * @param array $vars
 */
function elearning_alpha_preprocess_comment(&$vars) {
  $username = $vars['author'];
  $vars['submitted'] = $username . ' - ' .  t('@time ago', array('@time' => format_interval(REQUEST_TIME - $vars['comment']->created, 1)));
}
