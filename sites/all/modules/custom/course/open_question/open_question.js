/* 
 * @file contents js for feedback process on open question review list.
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
        var textarea = $(this).parents('.views-field-feedback-form').find('textarea[name="review"]').val();
        review.removeClass('.form-item-inactive').addClass('form-item-active');
        submit.addClass('form-item-active');
        submit_wo_text.attr('disabled', 'disabled').removeClass('form-item-active');
        if (this.selectedIndex <= 3) {  
          if (textarea === '') {
            submit.attr('disabled', 'disabled').addClass('disabled');
          }
        } else {
          if (textarea === '') {
            submit_wo_text.removeAttr('disabled').addClass('form-item-active');
          } else {
            submit_wo_text.attr('disabled', 'disabled').removeClass('form-item-active');
          }
          submit.removeClass('disabled').removeAttr('disabled');
        }
        var rating_submit = $(this).parents('.views-field-feedback-form').find('.oq-review-form-rating-submit');
        if (rating_submit.length > 0) {
          rating_submit.trigger('mousedown');
        }
      });
      $('textarea[name="review"]').keyup(function() {
        var select = $(this).parents('.views-field-feedback-form').find('select[name="rating"]');
        var rating = select[0].selectedIndex;
        var text = $(this).val().length;
        if (text < 1 && rating > 3) {
          $(this).parents('.views-field-feedback-form').find('.oq-review-form-submit-wo-text').addClass('form-item-active').removeAttr('disabled');
        } else {
          if (text >= 1) {
            $(this).parents('.views-field-feedback-form').find('.oq-review-form-submit-wo-text').removeClass('form-item-active').attr('disabled', 'disabled');
          }
        }
        if (text < 4 && rating <= 3) {
          $(this).parents('.views-field-feedback-form').find('.oq-review-form-submit-button').attr('disabled', 'disabled').addClass('disabled');
        } else {
          if ((text >= 4 && rating <= 3) || (rating > 3)) {
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
