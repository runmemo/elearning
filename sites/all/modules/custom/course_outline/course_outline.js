/** 
 * @file 
 * course_outline.js for course outline navigation
 */

(function($) {
  Drupal.behaviors.course_outline_accordion = {
    attach: function(context, settings) {
     
      $('.js-outline-unit').unbind('click').bind('click', function() {
        $(this).next('ul').slideToggle().css('display', 'inline-block');
        $(this).toggleClass('active');
      });
      // open section with active page
      $('.block-course-outline .menu > ul').css('display', 'none');
      $('.block-course-outline .active').closest('ul').css('display', 'inline-block');

      $('.book-navigation a.page-up').html($('.block-course-outline a.active').html());
      $('.book-navigation a.page-up').attr('href', '#');
    }
  };
})(jQuery);
