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
      $('a.comment-link').mousedown(function() {
        $(this).parent().parent().find('.views-inline-comment-field-alias').show();
        $(this).parent().addClass('hidden');
        $(this).click();
      });
      $('a.views-inline-comment-link-alias').click(function() {
        $(this).parent().hide();
        $(this).parent().parent().find('.views-field-comment-count').removeClass('hidden');
        $(this).parents('.views-row').find('.formcloselink').trigger('click');
        $(this).parents('.views-row').find('.closelink').trigger('click');
        
      });
    }
  };
})(jQuery);
