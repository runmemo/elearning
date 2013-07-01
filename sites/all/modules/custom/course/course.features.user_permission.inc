<?php

/**
 * Implements hook_user_default_permissions().
 */
function course_user_default_permissions() {
  $permissions = array();
   
  // Exported permission: access comments.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: administer comments.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: edit own comments.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'comment',
  );

  // Exported permission: post comments.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'comment',
  );

  // Exported permission: add content to books.
  $permissions['add content to books'] = array(
    'name' => 'add content to books',
    'roles' => array(
      'administrator' => 'administrator',
      'teacher' => 'teacher',
    ),
    'module' => 'book',
  );

  // Exported permission: add media from remote sources.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'administrator' => 'administrator',
      'teacher' => 'teacher',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: administer book outlines.
  $permissions['administer book outlines'] = array(
    'name' => 'administer book outlines',
    'roles' => array(
      'administrator' => 'administrator',
      'teacher' => 'teacher',
    ),
    'module' => 'book',
  );

  // Exported permission: create course content.
  $permissions['create course content'] = array(
    'name' => 'create course content',
    'roles' => array(
      'administrator' => 'administrator',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: create files.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'teacher' => 'teacher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: create new books.
  $permissions['create new books'] = array(
    'name' => 'create new books',
    'roles' => array(
      'administrator' => 'administrator',
      'teacher' => 'teacher',
    ),
    'module' => 'book',
  );

  // Exported permission: edit own course content.
  $permissions['edit own course content'] = array(
    'name' => 'edit own course content',
    'roles' => array(
      'administrator' => 'administrator',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own files.
  $permissions['edit own files'] = array(
    'name' => 'edit own files',
    'roles' => array(
      'teacher' => 'teacher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: view files.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'teacher' => 'teacher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: view own files.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'teacher' => 'teacher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: view own private files.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'teacher' => 'teacher',
    ),
    'module' => 'file_entity',
  );

  return $permissions;
}
