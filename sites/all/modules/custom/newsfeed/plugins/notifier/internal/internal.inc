<?php
$plugin = array(
  'title' => t('Internal'),
  'description' => t('Send Internal Message'),
  'class' => 'MessageNotifierInternal',
  'view_modes' => array(
    'message_notify_internal_body' => array('label' => t('Notify - Internal body')),
  ),
);
