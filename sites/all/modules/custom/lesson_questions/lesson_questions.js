(function ($) {
  Drupal.behaviors.lesson_questions = {
    attach: function(context, settings) {
      $('span.close').click(function() {
        $(this).parent().hide('fast');
      });
      $('.view-relevant-questions.view-id-relevant_questions .views-field-field-answer-count .field-content').each(function() {
        if($(this).text() <= 0) {
          $(this).parent().parent().addClass('zero');
        }
      });
    }
  };
})(jQuery);
