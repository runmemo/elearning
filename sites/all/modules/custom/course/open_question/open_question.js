/* 
 * @file conteins js for best answer selection process
 */

(function($) {
  Drupal.behaviors.other_answers_review_list = {
    attach: function(context, settings) {
      // inline comments behavior
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
      // feedback form behavior
      $('a.oq-review-link', context).unbind('click').bind('click', function() {
        $(this).parents('.views-field-feedback-form').find('.form-item-review').toggleClass('form-item-active');
        $(this).parents('.views-field-feedback-form').find('.form-submit').toggleClass('form-item-active');
      });
      $('select[name="rating"]').change(function() {
        if (this.selectedIndex <= 3) {
          $(this).parents('.views-field-feedback-form').find('.form-item-review').addClass('form-item-active');
          $(this).parents('.views-field-feedback-form').find('.form-submit').addClass('form-item-active');
        } else {
          // @todo check whether form is active or not, as it is strange to submit form like that once it is open.
          $(this).parents('.views-field-feedback-form').find('.form-submit').trigger('mousedown');
        }
      });
      $('select[name="rating"][class~="error"]').parents('.views-field-feedback-form').find('.form-item-review').addClass('form-item-active');
      $('select[name="rating"][class~="error"]').parents('.views-field-feedback-form').find('.form-submit').addClass('form-item-active');
      $('textarea[name="review"][class~="error"]').parents('.views-field-feedback-form').find('.form-item-review').addClass('form-item-active');
      $('textarea[name="review"][class~="error"]').parents('.views-field-feedback-form').find('.form-submit').addClass('form-item-active');
    }
  };
})(jQuery);
