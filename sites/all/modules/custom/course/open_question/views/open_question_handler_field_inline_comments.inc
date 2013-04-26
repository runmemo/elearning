<?php

/**
 * @file
 * Views Handler custom class, that is mostly copy of the class from
 * Inline Comments module. We need this override in order to always show the list of comments.
 */
class open_question_handler_field_inline_comments extends views_handler_field {

  var $output;

  function query() {
    drupal_add_css(drupal_get_path('module', 'comments') . '/comment.css');
    drupal_add_css(drupal_get_path('module', 'inline_comments') . '/css/inline_comments_views.css');
    drupal_add_js(drupal_get_path('module', 'inline_comments') . '/js/loadComments.js');
    drupal_add_js(drupal_get_path('module', 'inline_comments') . '/js/reformatPager.js');
    drupal_add_js(drupal_get_path('module', 'inline_comments') . '/js/loadPager.js');
    drupal_add_js(drupal_get_path('module', 'inline_comments') . '/js/reply.js');
    //      drupal_add_js(drupal_get_path('module', 'inline_comments') . '/js/charCount.js');
    drupal_add_js(drupal_get_path('module', 'inline_comments') . '/js/ajaxPoster.js');
    drupal_add_js(drupal_get_path('module', 'inline_comments') . '/js/comment_toggle.js');
    $this->query->add_field('node', 'type');
    $this->query->add_field('node', 'uid');
    $this->query->add_field('node_comment_statistics', 'comment_count');
  }

  function render($values) {
    global $user;
    $output = '<div class="node-nid">' . $values->nid . '</div>';
    $output .= '<div class="user-uid">' . $user->uid . '</div>';
    // load and render comments
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
    if (user_access('access comments')) {
      switch ($values->node_comment_statistics_comment_count) {
        case 0:
          $output .= l(t('0 Comments'), 'node/' . $values->nid, array('attributes' => array('class' => 'comment-click')));
          break;
        case 1:
          $output .= l(t('View 1 Comment'), 'node/' . $values->nid, array('attributes' => array('class' => 'comment-click')));
          break;
        default:
          $numcomments = array('@numcomments' => $values->node_comment_statistics_comment_count);
          $string = t('View @numcomments Comments', $numcomments);
          $output .= l($string, 'node/' . $values->nid, array('attributes' => array('class' => 'comment-click')));
          break;
      }
    }
    if (user_access('skip comment approval')) {
      $output .= '<div class="views-inline-comment-field-alias"><a class="views-inline-comment-link-alias">' . t('Hide Comment') . '</a></div>';
      $output .= '<div class="views-inline-comment-field">' . l(t('Add Comment'), 'comment/reply/' . $values->nid, array('attributes' => array('class' => 'comment-link'))) . '</div>';
    }
    return $output;
  }

}