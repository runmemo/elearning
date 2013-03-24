/* 
 * @file conteins js for course outline navigation
 */

(function ($) {
  Drupal.behaviors.course_outline_accordion = {    
    attach: function(context, settings) {
      $('.block-course-outline h3').click(function () {
        $(this).next('ul').slideToggle();
      });
	// open section with active page
        $('.block-course-outline .menu > ul').hide();
	$('.block-course-outline .active').closest('ul').show();    
    }
  };
})(jQuery);
