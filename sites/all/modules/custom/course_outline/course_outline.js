/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */




(function ($) {
  Drupal.behaviors.course_outline_accoridan = {
    attach: function(context,settings) {
      // if this node is in an iframe, show only the content
      jQuery('.block-course-outline').accordion({
        header: 'h3',
      });
    }
  }
})(jQuery)
