<?php




/**
 * Registers user to specified course
 * @param integer $uid - id of user to register
 * @param integer $nid - id of the course
 * @return integer node id of new registration.
 */
function course_register($uid, $nid) {
    
    // check whether registration already exists
    // @todo
    $rid = course_registration_id($uid, $nid);
    if ($rid) {
        return $rid;
    }
    
    $reg_array = array (
      'uid' => $uid, 
      'nid' => $nid,
      'created' => time(),
    );
    // create new registration node
    $registration = entity_create('registration', $reg_array);
    $registration->save();
    return $registration->registration_id;
}

/**
 * Checks whether registration exists for user and course
 * @param integer $uid user id
 * @param integer $nid course id
 */
function course_registration_id($uid, $nid, $active = TRUE) {
    if (! (bool) $uid) {
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
      foreach($rids as $rid) {
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
        $registration->cancelled  = time();
        $registration->save();
        
        return TRUE;
    } else { // registration does not exist or was cancelled   
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
   
    if (isset($node->book)) { // node is part of a book
      $book = $node->book;
      
      if($book['depth'] != 3) { 
        // here we just check whether it's course item level
        return NULL; 
      }
      
      if (!(bool)($account->uid)) {
        return FALSE; // anonymous account
      }
      
       $course_nid = $book['bid'];
       
       $rid = course_registration_id($account->uid, $course_nid);
       if ($rid) { // user is registered
           return TRUE;
       }
       else { // user is not registered for a course
           return FALSE;
       }
    } 
    else { // this node is not part of a book
        return NULL;
    } 
}
