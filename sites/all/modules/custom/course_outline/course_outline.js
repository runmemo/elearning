/** 
 * @file 
 * course_outline.js for course outline navigation
 */

(function($) {
  Drupal.behaviors.course_outline_accordion = {
    attach: function(context, settings) {
      $('.js-outline-unit').unbind('click').bind('click', function() {
        $(this).next('ul').toggle();
        $(this).toggleClass('active');
      });
      // open section with active page
      $('.block-course-outline .menu > ul').css('display', 'none');
      $('.block-course-outline .active').closest('ul').toggle();
      $('.block-course-outline .active').closest('ul').prev().toggleClass('active');
    }
  };
})(jQuery);

(function($) {
   Drupal.behaviors.course_outline_certificate = {
    attach: function(context, settings) {
      // define certificate popup position and show it
      $('.outline-certificate-text').hover(function() {
        var height = $('.outline-certificate-desc-wrapper').height() / 2;
        var left = $(this).width() * 2;
        $('.outline-certificate-desc-triangle').css('top', height - 5).css('left', -10);
        $('.outline-certificate-desc-wrapper').css('top', 10 - height).css('left', left).fadeToggle('slow');
      });
    }
  };
})(jQuery);
