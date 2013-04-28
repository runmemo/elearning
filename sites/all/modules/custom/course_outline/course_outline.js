/** 
 * @file 
 * course_outline.js for course outline navigation
 */

(function($) {
  Drupal.behaviors.course_outline_accordion = {
    attach: function(context, settings) {
      $('.block-course-outline h3').last().addClass('last');
      // add background to a instead of li, because of progress-bar
      $('.block-course-outline li').hover(
        function() {
        $(this).find('a').addClass('hovered');
      },
        function() {
          $(this).find('a').removeClass('hovered');
        });
      $('.block-course-outline a.active').parent().parent().prev().addClass('active');
      $('.block-course-outline h3').unbind('click').bind('click', function() {
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
