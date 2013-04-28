<?php
/**
 * @file
 * registration.views.inc
 */

function registration_views_data_alter(&$data) { 
         // Expose the uid as a relationship to users.
    $data['registration']['uid'] = array(
        'title' => t('User'),
        'help' => t('Registered user'),
        'relationship' => array(
            'base' => 'users',
            'base field' => 'uid',
            'relationship field' => 'uid',
            'handler' => 'views_handler_relationship',
            'label' => t('user'),
        ),
    );    
    
    $data['registration']['nid'] = array(
        'title' => t('Node'),
        'help' => t('Node to which user registered'),
        'relationship' => array(
            'base' => 'node',
            'base field' => 'nid',
            'relationship field' => 'nid',
            'handler' => 'views_handler_relationship',
            'label' => t('node'),
        ),
    ); 
    
}