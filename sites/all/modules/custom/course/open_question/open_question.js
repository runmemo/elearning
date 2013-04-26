/* 
 * @file conteins js for best answer selection process
 */

(function($) {
  Drupal.behaviors.other_answers_review_list = {
    attach: function(context, settings) {
      // inline comments behavior
      $('a.comment-link').mousedown(function() {
        $(this).click();
        $(this).parent().parent().find('.views-inline-comment-field-alias').show();
        $(this).parent().addClass('hidden');
        // insert comment form after list of comments
        var comments = $(this).parents('.views-row').find('.comment-group');
        $(this).parents('.views-row').find('.comment-form').insertAfter(comments);
      });
      $('.comment-form').find('.form-submit').click(function() {
        $(this).parents('.views-row').find('.views-inline-comment-field-alias').hide();
        $(this).parents('.views-row').find('.views-inline-comment-field').removeClass('hidden').find('.comment-link').click();
      });
      // hide comments form
      $('a.views-inline-comment-link-alias').click(function() {
        $(this).parent().hide();
        $(this).parent().parent().find('.views-inline-comment-field').removeClass('hidden');
        $(this).parents('.views-row').find('.formcloselink').trigger('click');
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
          var textarea = $(this).parents('.views-field-feedback-form').find('textarea[name="review"]');
          if (textarea.val() === '') {
            $(this).parents('.views-field-feedback-form').find('.form-submit').attr('disabled', 'disabled').addClass('disabled');
          }
        } else {
          // @todo check whether form is active or not, as it is strange to submit form like that once it is open.
          $(this).parents('.views-field-feedback-form').find('.form-submit').trigger('mousedown');
        }
      });
      $('textarea[name="review"]').keyup(function() {
        var select = $(this).parents('.views-field-feedback-form').find('select[name="rating"]');
        if ($(this).val().length < 4 && select[0].selectedIndex <= 3) {
          $(this).parents('.views-field-feedback-form').find('.form-submit').attr('disabled', 'disabled').addClass('disabled');
        } else {
          if (($(this).val().length >= 4 && select[0].selectedIndex <= 3) || (select.selectedIndex > 3)) {
            $(this).parents('.views-field-feedback-form').find('.form-submit').removeClass('disabled').removeAttr('disabled');
          }
        }
      });
      $('select[name="rating"][class~="error"]').parents('.views-field-feedback-form').find('.form-item-review').addClass('form-item-active');
      $('select[name="rating"][class~="error"]').parents('.views-field-feedback-form').find('.form-submit').addClass('form-item-active');
      $('textarea[name="review"][class~="error"]').parents('.views-field-feedback-form').find('.form-item-review').addClass('form-item-active');
      $('textarea[name="review"][class~="error"]').parents('.views-field-feedback-form').find('.form-submit').addClass('form-item-active');
    }
  };
})(jQuery);
