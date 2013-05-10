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
      // bind event from flag module
      $(document).bind('flagGlobalBeforeLinkUpdate', function(event, data) {
        if (data.contentId > 0 && data.flagName === 'best_answer' && data.flagStatus === 'flagged') {
          $('.flag-best-answer a.unflag-action').each(function() {
            $(this).removeClass('unflag-action').addClass('flag-action');
            this.href = this.href.replace('flag/unflag', 'flag/flag');
          });
        }
      });
    }
  };
})(jQuery);
