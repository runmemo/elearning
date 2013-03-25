/* 
 * @file conteins js for course outline navigation
 */

(function ($) {
  Drupal.behaviors.course_outline_accordion = {    
    attach: function(context, settings) {
        $('.block-course-outline h3').last().addClass('last');
        $('.block-course-outline a.active').parent().parent().prev().addClass('active');
        $('.block-course-outline h3').unbind('click').bind('click', function () {
          $(this).next('ul').slideToggle();
          $(this).toggleClass('active');
        });
	// open section with active page
        $('.block-course-outline .menu > ul').hide();
	$('.block-course-outline .active').closest('ul').show();

        $('.book-navigation a.page-up').html($('.block-course-outline a.active').html());
        $('.book-navigation a.page-up').attr('href', '#');   
    }
  };
})(jQuery);
