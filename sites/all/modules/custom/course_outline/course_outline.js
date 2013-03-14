/* 
 * @file conteins js for course outline navigation
 */

(function ($) {
  Drupal.behaviors.course_outline_accordion = {
    attach: function(context, settings) {
      // if this node is in an iframe, show only the content
     $('.block-course-outline').accordion({
        header: 'h3',
        active: 1,
        navigation: true,
        autoHeight: false
      });
    }
  };
})(jQuery);
