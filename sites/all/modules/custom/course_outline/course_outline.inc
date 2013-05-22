<?php

/**
 * Helper counter class allows to keep several counts.
 */
class multi_counter {

  private $counts;

  public function __construct() {
    $this->counts = array();
  }

  /**
   * Increments counter of specific type by one.
   * 
   * @param string $type
   *   Type for which count will be incremented.
   * 
   * @return integer
   *   Times increment() was called including current call.
   */
  public function increment($type) {
    if (!isset($this->counts[$type])) {
      return $this->counts[$type] = 1;
    }
    else {
      return ++$this->counts[$type];
    }
  }

  /**
   * Gets current value of counter without changing counts.
   * 
   * @param string $type
   *   Type for which number of counts is needed.
   * 
   * @return integer
   *   Times increment was called for provided type.
   */
  public function current($type) {
    if (!isset($this->counts[$type])) {
      return 0;
    }
    else {
      return $this->counts[$type];
    }
  }

}