(function ($) {
  Drupal.behaviors.lesson_questions = {
    attach: function(context, settings) {
      $('span.close').click(function() {
        $(this).parent().hide('fast');
      });
      $('.view-relevant-questions-list .views-field-field-answer-count .field-content').each(function() {
        if($(this).text() <= 0) {
          $(this).parent().parent().addClass('zero');
        }
      });

        $('li a.active').parent().addClass('active');
    }
  };
})(jQuery);
