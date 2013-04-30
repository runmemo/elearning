<?php

/**
 * @file
 * Subscriptions Content module (admin functions).
 */


/**
 * Build the Categories subscription form at user/UID/subscriptions/taxa.
 *
 * @param array $form
 * @param int $uid
 * @param array $vocabularies
 *   ID of a user if >0 or of a role if <0.
 *
 * @return array
 *
 * @ingroup form
 */
function _subscriptions_question_form(array $form, $uid) {
  $tr = 't';
  $subscriptions = array();
  $query = db_select('node', 'n', array('fetch' => PDO::FETCH_ASSOC))
    ->extend('PagerDefault')
    ->limit(50);
  $query
    ->fields('n', array('nid', 'uid', 'title', 'status', 'changed'))
    ->join('subscriptions', 's', (db_driver() != 'pgsql' ? 'n.nid = s.value' : 'CAST(n.nid AS VARCHAR) = s.value'));
  $query
    ->fields('s', array('send_interval', 'author_uid', 'send_comments', 'send_updates'));
  if (module_exists('comment')) {
    $query
      ->leftJoin('node_comment_statistics', 'ncs', 'n.nid = ncs.nid');
    $query
      ->fields('ncs', array('last_comment_timestamp'));
    $query->addExpression('CASE WHEN s.send_comments + s.send_updates = 0 THEN n.created
                                WHEN s.send_comments + s.send_updates = 2 THEN
                                     CASE WHEN n.changed > ncs.last_comment_timestamp THEN n.changed ELSE ncs.last_comment_timestamp END
                                WHEN s.send_comments = 1 THEN ncs.last_comment_timestamp
                                ELSE n.changed END', 'latest_activity');
  }
  else {
    $query->addExpression('IF(s.send_updates = 0, n.created, n.changed)', 'latest_activity');
  }
  $query
    ->condition('s.module', 'node')
    ->condition('s.field', 'field_answer_question')
    ->condition('s.recipient_uid', $uid)
    ->orderBy('latest_activity', 'desc')
    ->addTag('node_access');
  foreach ($query->execute() as $s) {
    $subscriptions[$s['nid']][$s['author_uid']] = $s;
  }

  if (module_exists('comment')) {
    // check whether we've commented:
    if (db_driver() == 'pgsql') {
      $select = db_select('subscriptions', 's');
      $select->addExpression('CAST(s.value AS decimal)', 'value');
      $select = $select
        ->condition('s.module', 'node')
        ->condition('s.field', 'nid')
        ->condition('s.recipient_uid', $uid);
    }
    else {
      $select = db_select('subscriptions', 's')
        ->fields('s', array('value'))
        ->condition('s.module', 'node')
        ->condition('s.field', 'nid')
        ->condition('s.recipient_uid', $uid);
    }
    $result = db_select('comment', 'c')
      ->fields('c', array('nid'))
      ->condition('c.nid', $select, 'IN')
      ->condition('c.uid', $uid)
      ->groupBy('c.nid')
      ->execute();
    foreach ($result as $c) {
      if (isset($subscriptions[$c->nid])) {
        foreach ($subscriptions[$c->nid] as $author_uid => $subscription) {
          $subscriptions[$c->nid][$author_uid]['commented'] = TRUE;
        }
      }
    }
    $fields = t('@latest_activity, @authored, @commented');
  }
  else {
    $fields = t('@latest_activity, @authored');
  }

  $form[0] = array(
    '#type' => 'item',
    '#title' => '',
    '#tree' => TRUE,
    '#theme' => 'subscriptions_form_table',
  );
  $defaults = array();
  foreach ($subscriptions as $nid => $bundle) {
    foreach ($bundle as $author_uid => $subscription) {
      $title = truncate_utf8($subscription['title'], 40);
      if ($title != $subscription['title']) {
        $title .= '...';
      }
      $title = l($title, 'node/' . $subscription['nid']);
      if (!$subscription['status']) {
        if (user_access('administer nodes')) {
          $title = SUBSCRIPTIONS_UNAVAILABLE . '&nbsp;' . $title;
        }
        else {
          continue;
        }
      }
      $subscription['extra_info'] = $tr($fields, array(
        '@latest_activity' => format_interval(time() - $subscription['latest_activity']),
        '@authored' => ($subscription['uid'] == $uid ? $tr('Yes') : $tr('No')),
        '@commented' => (!empty($subscription['commented']) ? $tr('Yes') : $tr('No')),
      ));
      subscriptions_form_helper($form[0], $defaults, $author_uid, $subscription['nid'], $title, $subscription);
    }
  }
  unset($form[0]['author']);

  if (count(element_children($form[0]))) {
    $form[0]['extra_info']['#title'] = $tr($fields, array('@latest_activity' => 'Latest activity', '@authored' => 'authored', '@commented' => 'commented'));
    $form[0]['defaults'] = array(
      '#type' => 'value',
      '#value' => $defaults,
    );
    subscriptions_form_column_filter($form[0], $uid);
    $form['note'] = array('#type' => 'item', '#description' => '<div>' . t('Note: Deactivated subscriptions will be removed from the list.') . '</div>' );
    $form['pager'] = array('#markup' => theme('pager', array('tags' => NULL, 'element' => 0, 'quantity' => 50)));
  }
  else {
    $form = array(array('#markup' => t('There are no available subscribed pages.')));
  }
  return $form;

}

