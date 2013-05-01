/* 
 * @file contents js for fedback process on open question review list.
 */

(function($) {
  Drupal.behaviors.open_question_review_list = {
    attach: function(context, settings) {
      $('.oq-review-form-edit-button').ajaxComplete(function(event, request, settings) {
        $(this).parents('.views-field-feedback-form').find('.form-item-review').addClass('form-item-active');
      });
      
      $('select[name="rating"]').change(function() {
        $(this).parents('.views-field-feedback-form').find('.form-item-review').addClass('form-item-active');
        $(this).parents('.views-field-feedback-form').find('.form-submit').addClass('form-item-active');
        if (this.selectedIndex <= 3) {
          var textarea = $(this).parents('.views-field-feedback-form').find('textarea[name="review"]');
          if (textarea.val() === '') {
            $(this).parents('.views-field-feedback-form').find('.form-submit').attr('disabled', 'disabled').addClass('disabled');
          }
        } else {
          $(this).parents('.views-field-feedback-form').find('.form-submit').removeClass('disabled').removeAttr('disabled');
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
