/* 
 * @file contents js for feedback process on open question review list.
 */

(function($) {
  Drupal.behaviors.open_question_review_list = {
    attach: function(context, settings) {
      
      function get_feedback_form(child) {
        return child.parents('.views-field-feedback-form');
      }
      
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
        var feedback_form = get_feedback_form($(this));
        var review = feedback_form.find('.form-item-inactive');
        var submit = feedback_form.find('.oq-review-form-submit');
        var button_skip = feedback_form.find('.oq-review-form-skip');
        var textarea = feedback_form.find('textarea[name="review"]').val();
        if (this.selectedIndex <= 3) {  
          if (textarea === '') {
            submit.prop('disabled', true);
          }
        } 
        else {
          if (textarea === '') {
            button_skip.hide();
          } else {
            button_skip.show();
          }
          submit.prop('disabled', false);
        }
        var rating_submit = feedback_form.find('.oq-review-form-rating-submit');
        if (rating_submit.length > 0) {
          rating_submit.trigger('mousedown');
        }
      });
      // 
      $('textarea[name="review"]').keyup(function() {
        var feedback_form = get_feedback_form($(this));
      //  console.debug(feedback_form);
        var select = feedback_form.find('select[name="rating"]');
        var rating = select[0].selectedIndex;
        console.debug(rating);
        var button_skip = feedback_form.find('.oq-review-form-skip');     
        var review_length = $(this).val().length;
        console.debug(review_length)
        if (review_length < 1 && rating > 3) {
          button_skip.attr('disabled', true);
        } 
        else {
          if (review_length >= 1) {
            button_skip.prop('disabled', true);
          }
        }
        var btn_submit = feedback_form.find('.oq-review-form-submit');
        if (review_length < 4 && rating <= 3) {
          btn_submit.prop('disabled', true);
        } else {
          if ((review_length >= 4 && rating <= 3) || (rating > 3)) {
            btn_submit.prop('disabled', false);
          }
        }
      });

      $('select[name="rating"][class~="error"]').parents('.views-field-feedback-form').find('.is-inactive').removeClass('.is-inactive').addClass('is-active');
      $('select[name="rating"][class~="error"]').parents('.views-field-feedback-form').find('.form-submit').addClass('is-active');
      $('textarea[name="review"][class~="error"]').parents('.views-field-feedback-form').find('.is-inactive').removeClass('.is-inactive').addClass('is-active');
      $('textarea[name="review"][class~="error"]').parents('.views-field-feedback-form').find('.form-submit').addClass('is-active');
    }
  };
})(jQuery);
