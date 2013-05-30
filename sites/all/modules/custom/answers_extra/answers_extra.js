/* 
 * @file contents js for feedback process on open question review list.
 */

(function($) {
  Drupal.behaviors.answers_extra = {
    attach: function(context, settings) {

      // Hover tooltip on OQ2 edit form.
      $(".ae-answer-form-edit")
        .mouseenter(function() {
          $(this).next(".description").show();
        })
        .mouseleave(function() {
          $(this).next(".description").hide();
        });

    }
  };
})(jQuery);


