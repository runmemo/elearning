/* 
 * @file contents js for fedback process on open question review list.
 */

(function($) {
  Drupal.behaviors.open_question_review_list = {
    attach: function(context, settings) {
      $('.oq-review-form-view').ready(function() {
        $('.oq-review-form-view .star').each(function(index, element) {
          if (!$(this).hasClass('on')) {
            $(this).addClass('off');
          }
          $(this).hover(function() {
            $(this).nextAll('.star').toggleClass('view-on');
          });
        });
      });

      $('select[name="rating"]').change(function() {
        var review = $(this).parents('.views-field-feedback-form').find('.form-item-inactive');
        var submit = $(this).parents('.views-field-feedback-form').find('.oq-review-form-submit-button');
        var submit_wo_text = $(this).parents('.views-field-feedback-form').find('.oq-review-form-submit-wo-text');
        review.removeClass('.form-item-inactive').addClass('form-item-active');
        submit.addClass('form-item-active');
        if (this.selectedIndex <= 3) {
          var textarea = $(this).parents('.views-field-feedback-form').find('textarea[name="review"]');
          if (textarea.val() === '') {
            submit.attr('disabled', 'disabled').addClass('disabled');
            submit_wo_text.addClass('form-item-active');
            submit_wo_text.removeAttr('disabled');
          }
        } else {
          submit.removeClass('disabled').removeAttr('disabled');
          submit_wo_text.attr('disabled', 'disabled').removeClass('form-item-active');
        }
        var rating_submit = $(this).parents('.views-field-feedback-form').find('.oq-review-form-rating-submit');
        if (rating_submit.length > 0) {
          rating_submit.trigger('mousedown');
        }
      });

      $('textarea[name="review"]').keyup(function() {
        var select = $(this).parents('.views-field-feedback-form').find('select[name="rating"]');
        if ($(this).val().length < 4 && select[0].selectedIndex <= 3) {
          $(this).parents('.views-field-feedback-form').find('.oq-review-form-submit-button').attr('disabled', 'disabled').addClass('disabled');
        } else {
          if ($(this).val().length === 0) {
            $(this).parents('.views-field-feedback-form').find('.oq-review-form-submit-wo-text').removeClass('disabled').removeAttr('disabled');
          }
          if (($(this).val().length >= 4 && select[0].selectedIndex <= 3) || (select.selectedIndex > 3)) {
            $(this).parents('.views-field-feedback-form').find('.oq-review-form-submit-button').removeClass('disabled').removeAttr('disabled');
          }
        }
      });

      $('select[name="rating"][class~="error"]').parents('.views-field-feedback-form').find('.form-item-inactive').removeClass('.form-item-inactive').addClass('form-item-active');
      $('select[name="rating"][class~="error"]').parents('.views-field-feedback-form').find('.form-submit').addClass('form-item-active');
      $('textarea[name="review"][class~="error"]').parents('.views-field-feedback-form').find('.form-item-inactive').removeClass('.form-item-inactive').addClass('form-item-active');
      $('textarea[name="review"][class~="error"]').parents('.views-field-feedback-form').find('.form-submit').addClass('form-item-active');
    }
  };
})(jQuery);
