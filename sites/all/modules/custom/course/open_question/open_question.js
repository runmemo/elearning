/* 
 * @file conteins js for best answer selection process
 */

(function($) {
  Drupal.behaviors.open_question_best_answer = {
    attach: function(context, settings) {
      $('a.flag-action').each(function() {
        $(this).click(function() {
          $('a.unflag-action').click();
        });
      });
    }
  };
})(jQuery);
