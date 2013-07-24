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

(function($) {
   Drupal.behaviors.course_outline_certificate = {
    attach: function(context, settings) {
      // define certificate popup position and show it
      $('.outline-certificate-points').hover(
        function(e) {
          $tooltip = get_tooltip($(this));
          var height = $tooltip.height() / 2;
          var left = e.pageX - $(this).offset().left + 20;
          left = Math.max(left, $(this).width() * 2 / 3);
          $tooltip.find('.tooltip-triangle').css('top', height - 5).css('left', -10);
          $tooltip.css('top', 10 - height).css('left', left).fadeIn(200);
        },
        function(e) {
          $tooltip = get_tooltip($(this));
          $tooltip.stop(true, true).fadeOut();
        });
      
      function get_tooltip($element) {
        return $element.find('.tooltip-wrapper');
      }
    }
  };
})(jQuery);

(function($) {
  Drupal.behaviors.course_outline_item_add = {
    attach: function(context, settings) {
      console.log('init');
      $('#course-add-item-lesson').ajaxStart(function(){  
        console.log('start');
        $(".form-submit").attr("disabled", "disabled");
      });
      $('#course-add-item-lesson').ajaxStop(function(){  
        console.log('stop');
        $(".form-submit").removeAttr("disabled");
      });
    }
  };
})(jQuery);
