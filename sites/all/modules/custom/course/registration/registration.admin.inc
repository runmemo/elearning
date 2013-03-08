<?php

/**
 * @file
 * Registration editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

/**
 * UI controller.
 */
class RegistrationUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    
    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;
    
    $items['admin/structure/registration/manage'] = array(
      'title' => 'Registration Admin',
      'description' => 'Manage registration structure',
      'page callback' => 'registration_info',
      'access arguments' => array('administer registrations'),
    );
    $items['registration/%registration'] = array(
      'title callback' => 'registrations_page_title',
      'title arguments' => array(1),
      'page callback' => 'registrations_page_view',
      'page arguments' => array(1),
      'access arguments' => array('view registrations'),
      'type' => MENU_CALLBACK,
    );
    
    $items['registration/add'] = array(
        'title' => 'Add Registration',
        'page callback' => 'registration_add_page',
        'access arguments' => array('create registration'),
     );
    
    return $items;
    
    
 
    $items[$this->path] = array(
      'title' => 'Registrations',
      'description' => 'Add edit and update registrations.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );
    
    // Change the overview menu type for the list of registrations.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    
    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add a registration',
      'description' => 'Add a new registration',
      'page callback'  => 'registration_add_page',
      'access callback'  => 'registration_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'registration.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])

    );
    
    // Loading and editing registration entities
    $items[$this->path . '/registration/' . $wildcard] = array(
      'page callback' => 'registration_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'registration_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'registration.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/registration/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );
    
    $items[$this->path . '/registration/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'registration_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'registration_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'registration.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    // Menu item for viewing registrations
    $items['registration/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'registration_page_title',
      'title arguments' => array(1),
      'page callback' => 'registration_page_view',
      'page arguments' => array(1),
      'access callback' => 'registration_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }
  
  
  /**
   * Create the markup for the add Registration Entities page within the class
   * so it can easily be extended/overriden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('registration_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a registration.
 *
 * @param $registration
 *   The registration object being edited by this form.
 *
 * @see registration_edit_form()
 */
function registration_form_wrapper($registration) {
  // Add the breadcrumb for the form's location.
  registration_set_breadcrumb();
  return drupal_get_form('registration_edit_form', $registration);
}


/**
 * Form callback wrapper: delete a registration.
 *
 * @param $registration
 *   The registration object being edited by this form.
 *
 * @see registration_edit_form()
 */
function registration_delete_form_wrapper($registration) {
  // Add the breadcrumb for the form's location.
  //registration_set_breadcrumb();
  return drupal_get_form('registration_delete_form', $registration);
}


/**
 * Form callback: create or edit a registration.
 *
 * @param $registration
 *   The registration object to edit or for a create form an empty registration object
 *     with only a registration type defined.
 */
function registration_edit_form($form, &$form_state, $registration) {
  // Add the default field elements.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Registration Name'),
    '#default_value' => isset($registration->name) ? $registration->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
  
  $form['data']['#tree'] = TRUE;
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting registration switch'),
    '#default_value' => isset($registration->data['sample_data']) ? $registration->data['sample_data'] : 1,
  );

  // Add the field related form elements.
  $form_state['registration'] = $registration;
  field_attach_form('registration', $registration, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save registration'),
    '#submit' => $submit + array('registration_edit_form_submit'),
  );
  
  if (!empty($registration->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete registration'),
      '#suffix' => l(t('Cancel'), 'admin/content/registrations'),
      '#submit' => $submit + array('registration_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'registration_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the registration form
 */
function registration_edit_form_validate(&$form, &$form_state) {
  $registration = $form_state['registration'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('registration', $registration, $form, $form_state);
}


/**
 * Form API submit callback for the registration form.
 * 
 * @todo remove hard-coded link
 */
function registration_edit_form_submit(&$form, &$form_state) {
  
  $registration = entity_ui_controller('registration')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the registration and go back to the list of registrations
  
  // Add in created and changed times.
  if ($registration->is_new = isset($registration->is_new) ? $registration->is_new : 0){
    $registration->created = time();
  }

  $registration->changed = time();
  
  $registration->save();
  $form_state['redirect'] = 'admin/content/registrations';
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function registration_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/registrations/registration/' . $form_state['registration']->registration_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a registration.
 *
 * @param $registration
 *   The registration to delete
 *
 * @see confirm_form()
 */
function registration_delete_form($form, &$form_state, $registration) {
  $form_state['registration'] = $registration;

  $form['#submit'][] = 'registration_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete registration %name?', array('%name' => $registration->name)),
    'admin/content/registrations/registration',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for registration_delete_form
 */
function registration_delete_form_submit($form, &$form_state) {
  $registration = $form_state['registration'];

  registration_delete($registration);

  drupal_set_message(t('The registration %name has been deleted.', array('%name' => $registration->name)));
  watchdog('registration', 'Deleted registration %name.', array('%name' => $registration->name));

  $form_state['redirect'] = 'admin/content/registrations';
}



/**
 * Page to add Registration Entities.
 *
 * @todo Pass this through a proper theme function
 */
function registration_add_page() {
  $controller = entity_ui_controller('registration');
  return $controller->addPage();
}


/**
 * Sets the breadcrumb for administrative registration pages.
 */
function registration_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Registrations'), 'admin/content/registrations'),
  );

  drupal_set_breadcrumb($breadcrumb);
}



