(function($) {
  Drupal.behaviors.quiz_extra = {
    attach: function(context, settings) {

      $(".quiz-stat-popup")
        .mouseenter(function() {
          $(this).next("#quiz-stat-wrapper").show();
        })
        .mouseleave(function() {
          $(this).next("#quiz-stat-wrapper").hide();
        });

    }
  };
})(jQuery);


