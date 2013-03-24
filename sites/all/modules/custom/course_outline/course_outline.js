/* 
 * @file conteins js for course outline navigation
 */

(function ($) {
  Drupal.behaviors.course_outline_accordion = {    
    attach: function(context, settings) {
      $('.block-course-outline h3').click(function () {
        $(this).next('ul').slideToggle();
      });
	// @todo: open section with active page
	//$('. .active').closest('ul').prev().click();    
    }
  };
})(jQuery);
