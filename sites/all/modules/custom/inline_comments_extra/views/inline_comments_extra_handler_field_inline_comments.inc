<?php

/**
 * @file
 * Views Handler custom class, that is mostly copy of the class from
 * Inline Comments module. We need this override in order to always show the list of comments.
 */
class inline_comments_extra_handler_field_inline_comments extends inline_comments_handler_field_inline_comments {

  function render($values) {
    global $user;
    $output = '<div class="node-nid">' . $values->nid . '</div>';
    $output .= '<div class="user-uid">' . $user->uid . '</div>';
    // load and render comments
    if (user_access('access comments')) {
      $node = node_load($values->nid);
      $cids = comment_get_thread($node, variable_get('comment_default_mode_' . $node->type, 1), variable_get('comment_default_per_page_' . $node->type, 10));
      if (!empty($cids)) {
        $comments = comment_load_multiple($cids);
        comment_prepare_thread($comments);
        $build = comment_view_multiple($comments, $node);
        $build['pager']['#theme'] = 'pager';
        $output .= '<div class="comment-group">' . drupal_render($build) . '</div>';
      } else {
        $output .= '<div class="comment-group"></div>';
      }
      
      // this is required for contrib functionality to work:
      $numcomments = array('@numcomments' => $values->node_comment_statistics_comment_count);
      $string = t('View @numcomments Comments', $numcomments);
      $output .= l($string, 'node/' . $values->nid, array('attributes' => array('class' => 'comment-click')));
   
    }
    if (user_access('skip comment approval')) {
      $output .= '<div id="comment-form-show-' . $values->nid . '" class="views-inline-comment-field">' . l(t('Add Comment'), 'comment/reply/' . $values->nid, array('attributes' => array('class' => 'comment-link'))) . '</div>';
    }
    return $output;
  }

}