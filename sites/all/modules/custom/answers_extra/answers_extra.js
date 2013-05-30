/* 
 * @file contents js for feedback process on open question review list.
 */

(function($) {
  Drupal.behaviors.answers_extra = {
    attach: function(context, settings) {

      // Hover tooltip for answer edit.
      $(".ae-answer-form-edit")
        .mouseenter(function() {
          $(this).next(".description").show();
        })
        .mouseleave(function() {
          $(this).next(".description").hide();
        });

        $.each(Drupal.settings.answersExtra, function(index, value) {
          // get nid from index.
          var nid = index.substring(14);
          // if user dont have access to comment link remove link.
          if(value == false) {
            $("#comment-form-show-"+nid).remove();
          }
        });

    }
  };
})(jQuery);


