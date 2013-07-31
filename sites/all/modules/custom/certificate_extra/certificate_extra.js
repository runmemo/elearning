
(function($) {
   Drupal.behaviors.certificate = {
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
