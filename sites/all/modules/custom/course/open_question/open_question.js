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
      
      var comment = new RegExp('[\\?&]comment=([^&#]*)').exec(window.location.href);
      var review = new RegExp('[\\#](review|answer)([^&#]*)').exec(window.location.href);
      if (comment || review) {
        $('a[href="#qt-open_question_tabs-ui-tabs1"]', context).parent().removeClass('ui-tabs-selected').removeClass('ui-state-active');
        $('a[href="#qt-open_question_tabs-ui-tabs2"]', context).parent().addClass('ui-tabs-selected ui-state-active');
        $('#qt-open_question_tabs-ui-tabs1').addClass('ui-tabs-hide');
        $('#qt-open_question_tabs-ui-tabs2').removeClass('ui-tabs-hide');
        if (comment) {
          $(document).scrollTop( $('#comment-' + comment[1]).offset().top );
        }
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
        var nid = $(this).data('answer-nid');
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
        var nid = $(this).data('answer-nid');
        var rate_select = $('select[data-answer-nid="' + nid +'"]');
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


      // Hover tooltip on OQ2 edit form.
      $(".oq-review .oq-review-form-edit")
        .mouseenter(function() {
          $(this).next(".description").show();
        })
        .mouseleave(function() {
          $(this).next(".description").hide();
        });

    }
  };
})(jQuery);

/**
 * Create a degradeable star rating interface out of a simple form structure.
 *
 * Originally based on the Star Rating jQuery plugin by Wil Stuckey:
 * http://sandbox.wilstuckey.com/jquery-ratings/
 */
(function($){ // Create local scope.
  Drupal.behaviors.fivestar_override = {
    attach: function (context) {
      $('div.fivestar-form-item').once('fivestar', function() {
        var $this = $(this);
        var $container = $('<div class="fivestar-widget clearfix"></div>');
        var $select = $('select', $this);

        // Setup the cancel button
        var $cancel = $('option[value="0"]', $this);
        if ($cancel.length) {
          $('<div class="cancel"><a href="#0" title="' + $cancel.text() + '">' + $cancel.text() + '</a></div>')
            .appendTo($container);
        }

        // Setup the rating buttons
        var $options = $('option', $this).not('[value="-"], [value="0"]');
        var index = -1;
        $options.each(function(i, element) {
          var classes = 'star-' + (i+1);
          classes += (i + 1) % 2 == 0 ? ' even' : ' odd';
          classes += i == 0 ? ' star-first' : '';
          classes += i + 1 == $options.length ? ' star-last' : '';
          $('<div class="star"><a href="#' + element.value + '" title="' + element.text + '">' + '' + '</a></div>')
            .addClass(classes)
            .appendTo($container);
          if (element.value == $select.val()) {
            index = i + 1;
          }
        });

        $container.find('.star:lt(' + index + ')').addClass('on');
        $container.addClass('fivestar-widget-' + ($options.length));
        $container.find('a')
          .bind('click', $this, Drupal.behaviors.fivestar.rate)
          .bind('mouseover', $this, Drupal.behaviors.fivestar.hover);

        $container.bind('mouseover mouseout', $this, Drupal.behaviors.fivestar.hover);

        // Attach the new widget and hide the existing widget.
        $select.after($container).css('display', 'none');
      });
    },
  };
})(jQuery);
