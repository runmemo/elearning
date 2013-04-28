<?php
/**
 * @file
 * Contains api functions for the registration module
 */


/**
 * Registers user to specified course
 * @param integer $uid - id of user to register
 * @param integer $nid - id of the course
 * @return integer node id of new registration.
 */
function course_register($uid, $nid) {

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
 * Checks whether registration exists for user and course
 * @param integer $uid user id
 * @param integer $nid course id
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
  else { // registration for this course does not exist
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

/**
 * Permissions helper function that checks whether user is registered for a course
 * that contains page he is currently viewing.
 * @global type $user
 */
function course_user_access($node, $account) {

  if (!isset($node->book)) { // this node is not part of a book
    return NULL;
  }

  $book = $node->book;
  if ($book['depth'] != 3) {
    // here we just check whether it's course item level
    return NULL;
  }

  if (!(bool) ($account->uid)) {
    return FALSE; // anonymous account
  }

  $course_nid = $book['bid'];

  //Check if user is teacher of this course
  if (course_is_teacher($course_nid, $account->uid)) {
    return TRUE;
  }
  // check if user is registered to the course
  $rid = course_registration_id($account->uid, $course_nid);
  return (bool) $rid; 
}
