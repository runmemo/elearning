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
      //disable certificate download link
      $('.certificate-disabled a').click(function(e) {
        e.preventDefault();
      });
      // define certificate popup position and show it
      $('.outline-certificate-text').hover(function() {
        var height = $('.outline-certificate-desc-wrapper').height() / 2;
        var left = $(this).width() * 2;
        $('.outline-certificate-desc-triangle').css('top', height - 5).css('left', -10);
        $('.outline-certificate-desc-wrapper').css('top', 10 - height).css('left', left).fadeToggle('slow');
      });
      // open section with active page
      $('.block-course-outline .menu > ul').css('display', 'none');
      $('.block-course-outline .active').closest('ul').css('display', 'inline-block');

      $('.book-navigation a.page-up').html($('.block-course-outline a.active').html());
      $('.book-navigation a.page-up').attr('href', '#');
    }
  };
})(jQuery);
