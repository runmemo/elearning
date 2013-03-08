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
    
    // create new registration node
    $registration = entity_create('registration', array('uid' => $uid, 'nid' => $nid));
   // $registration->title = 'none';
   //$registration->uid = $uid;
   // $registration->nid = $nid;
    //$registration->field_create_date[LAGUAGE_NONE][0]['value'] = date('Y-m-d H:i:s');
    
    $registration->save();
    return $registration->nid;
}

/**
 * Checks whether registration exists for user and course
 * @param integer $uid user id
 * @param integer $nid course id
 */
function course_registration_id($uid, $nid) {
    
    // get id of top 1 registration
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'registration')
    //  ->propertyCondition('status', 1)
      ->propertyCondition('uid', $uid)
      ->propertyCondition('nid', $nid)
      ->range(0, 1);
    
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