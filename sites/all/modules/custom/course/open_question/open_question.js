/* 
 * @file conteins js for best answer selection process
 */

(function($) {
  Drupal.behaviors.other_answers_review_list = {
    attach: function(context, settings) {
      $('a.oq-review-link').click(function() {
        var form = $(this).parent();
        form.find('.form-item-review').fadeToggle('fast', 'linear');
        form.find('.form-submit').fadeToggle('fast', 'linear');
      });
    }
  };
})(jQuery);
