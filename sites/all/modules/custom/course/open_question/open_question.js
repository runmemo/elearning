/* 
 * @file contents js for feedback process on open question review list.
 */

(function($) {
  Drupal.behaviors.open_question_review_list = {
    attach: function(context, settings) {
      
      function get_feedback_form(element) {
        return element.parents('.views-field-feedback-form');
      }
      
      function get_answer_nid(element) {
        var form = get_feedback_form(element);
        var nid = form.find('.js-oq-answer-nid').val();
        return nid;
      }
      
      $('.oq-review-form-view').ready(function() {
        $(this).find('.star').each(function(index, element) {
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
        var nid = get_answer_nid($(this));
        var btn_submit = $('.js-oq-submit-review-' + nid);
        var btn_skip = $('.js-oq-skip-review-' + nid);
        var str_review = $('.js-oq-review-field-' + nid).val();
        var toggle_fields = $('.js-oq-form-toggle-' + nid);
        toggle_fields.show('fast');
        if (this.selectedIndex <= 3) {
          btn_skip.hide();
          if (str_review === '') {
            btn_submit.prop('disabled', true);
          }         
        }
        else {
          btn_submit.prop('disabled', false);
          if (str_review !== '') {
            btn_skip.hide();
          } 
          else {
            btn_skip.show();
          }
        }
        var rating_submit = feedback_form.find('.oq-review-form-rating-submit');
        if (rating_submit.length > 0) {
          rating_submit.trigger('mousedown');
        }
      });
      // 
      $('textarea[name="review"]').keyup(function() {
        var feedback_form = get_feedback_form($(this));
        var nid = get_answer_nid($(this));
        var select = feedback_form.find('select[name="rating"]');
        var rating = select[0].selectedIndex;
        var btn_skip = $('.js-oq-skip-review-' + nid);     
        var review_length = $(this).val().length;
        if (review_length < 1 && rating > 3) {
          btn_skip.show();
        } 
        else {
          if (review_length >= 1 && rating > 3) {
            btn_skip.hide();
          }
        }
        var btn_submit = $('.js-oq-submit-review-' + nid);
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
