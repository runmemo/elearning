(function ($) {
  Drupal.behaviors.lesson_questions = {
    attach: function(context, settings) {
      $('span.close').click(function() {
        $(this).parent().hide('fast');
      });
    }
  };
})(jQuery);
