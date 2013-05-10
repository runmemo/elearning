/* 
 * @file contents js for feedback process on open question review list.
 */

(function($) {
  Drupal.behaviors.open_question_review_list = {
    attach: function(context, settings) {
      
      function get_skip_review_button(nid) {
        return $('.js-oq-skip-review-' + nid);
      }
      
      function get_submit_button(nid) {
        return $('.js-oq-submit-review-' + nid);
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
        // @todo Ilya for some reason this is being called several times
        // on one star change. for me it is fired 3 times.
        var nid = $(this).data('feedback-nid');
        var btn_submit = get_submit_button(nid);
        var btn_skip = get_skip_review_button(nid);
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
        var rating_submit = $('.js-oq-form-rating-submit-' + nid);
        if (rating_submit.length > 0) {
          rating_submit.trigger('mousedown');
        }
      });
      // 
      $('textarea[name="review"]').keyup(function() {
        var nid = $(this).data('feedback-nid');
        var rate_select = $('select[data-feedback-nid="' + nid +'"]');
        var rating = rate_select.prop("selectedIndex");
        var btn_skip = get_skip_review_button(nid);    
        var review_length = $(this).val().length;
        if (review_length < 1 && rating > 3) {
          btn_skip.show();
        } 
        else {
          if (review_length >= 1 && rating > 3) {
            btn_skip.hide();
          }
        }
        var btn_submit = get_submit_button(nid);
        if (review_length < 4 && rating <= 3) {
          btn_submit.prop('disabled', true);
          btn_skip.hide();
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
