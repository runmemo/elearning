<?php
/**
 * @file
 * Contains api functions for the registration module
 */


/**
 * Registers user to a specified course.
 * 
 * @param integer $uid
 *   uid of user to register.
 * 
 * @param integer $nid
 *   nid of the course.
 * 
 * @return integer
 *   New registration's id.
 */
function registration_register($uid, $nid) {
  if (!(bool)$uid) {
    throw new InvalidArgumentException('User id must be greater than zero. Got $uid = ' . $uid);
  }

  //  check whether registration already exists
  $rid = course_registration_id($uid, $nid, FALSE);
  if ($rid) { // registration exists
    $registration = registration_load($rid);
    if ($registration->cancelled != 0) {
      $registration->cancelled = 0; // unset cancellation timestamp
      registration_save($registration);
    }
    return $rid;
  }

  // create new registration entity
  $reg_array = array(
    'uid' => $uid,
    'nid' => $nid,
    'created' => time(),
  );
  $registration = registration_create($reg_array);
  $registration->save();
  return $registration->registration_id;
}

/**
 * Gets id for registration with provided uid and nid.
 * 
 * @param integer $uid 
 *   User uid.
 * 
 * @param integer $nid 
 *   Course nid.
 * @return integer 
 *   Registration id if exists, FALSE if does not exist.
 */
function course_registration_id($uid, $nid, $active = TRUE) {
  if (!(bool) $uid) {
    return FALSE;
  }
  // get id of top 1 registration
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'registration')
      ->propertyCondition('uid', $uid)
      ->propertyCondition('nid', $nid);
  if ($active) { // filter cancelled registrations
    $query->propertyCondition('cancelled', 'NULL', '=');
  }
  $query->range(0, 1);
  $result = $query->execute();
  
  if (isset($result['registration'])) {
    $rids = array_keys($result['registration']);
    foreach ($rids as $rid) {
      return $rid;
    }
    return FALSE;
  }
  else { 
    // Registration for this course does not exist.
    return FALSE;
  }
}

/**
 * Cancels reigstration of specifed user for specified course
 * @param integer $uid
 * @param integer $nid
 * @return boolean shows wether registration was cancelled or not.
 */
function registration_cancel($uid, $nid) {

  $rid = course_registration_id($uid, $nid);
  if ($rid) { // active registration exists for this user
    $registration = registration_load($rid);
    $registration->cancelled = time();
    $registration->save();

    return TRUE;
  }
  else { // registration does not exist or was cancelled   
    return FALSE;
  }

  return TRUE;
}


function registration_node_registrations($nid) {
  // get id of top 1 registration
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'registration')
      ->propertyCondition('nid', $nid);
  $result = $query->execute();
  if (isset($result['registration'])) {
    $rids = array_keys($result['registration']);
    return $rids;
  }
  else 
  {
    return FALSE;
  }
}

function registration_user_registrations($uid) {
  // get id of top 1 registration
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'registration')
      ->propertyCondition('uid', $uid);
  $result = $query->execute();
  if (isset($result['registration'])) {
    $rids = array_keys($result['registration']);
    return $rids;
  }
  else 
  {
    return FALSE;
  }
}