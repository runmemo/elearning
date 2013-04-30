<?php

/**
 * Process variables for comment.tpl.php.
 * @param array $vars
 */
function elearning_alpha_preprocess_comment(&$vars) {
  $vars['submitted'] = t('!username - !time ago', array('!username' => $vars['author'], '!time' => format_interval(REQUEST_TIME - $vars['comment']->created, 1)));
}
