/** 
 * @file 
 * course_outline.js for course outline navigation
 */

(function($) {
  Drupal.behaviors.course_outline_accordion = {
    attach: function(context, settings) {
      if (!$('.js-outline-current').hasClass('active')) {
        $('.js-outline-current').addClass('active');
      }
      $('.js-outline-unit').unbind('click').bind('click', function() {
        $(this).next('.menu').slideToggle('fast');
        $(this).toggleClass('active');
      });
      // Open section with active page.
      $('.block-course-outline .menu > .menu').css('display', 'none');
      $('.block-course-outline .active').closest('.menu').css('display', 'inline-block');
      $('.block-course-outline .active').closest('.menu').prev('.js-outline-unit').toggleClass('active');
    }
  };
})(jQuery);
