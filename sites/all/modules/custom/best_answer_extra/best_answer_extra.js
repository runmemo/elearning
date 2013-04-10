/* 
 * @file conteins js for best answer selection process
 */

(function($) {
  Drupal.behaviors.best_answer_extra = {
    attach: function(context, settings) {
      var best = settings.best_answer;
      if (best && best.nid.length > 0) {
        $('.views-field-ops').each(function() {
          if ($(this).find('.field-content').empty() && $(this).find('#' + best.nid)) {
            $('#' + best.nid).addClass('best-answer-others');
          }
        });
      }
      var flagged = $('a.unflag-action');
      $('a.flag-action').each(function() {
        $(this).click(function() {
          $('a.flag').addClass('processing');
          setTimeout(function() {
            $('a.flag').removeClass('processing');
          }, 4000);
          setTimeout(function (){
            flagged.click();
          }, 2000);
        });
      });
    }
  };
})(jQuery);
