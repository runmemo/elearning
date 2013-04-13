(function ($) {
  Drupal.behaviors.relevant_answers_extra = {
    attach: function(context, settings) {
      $('span.close').click(function() {
        $(this).parent().hide('fast');
      });
    }
  };
})(jQuery);
