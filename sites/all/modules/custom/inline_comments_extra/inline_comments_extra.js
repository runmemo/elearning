/* 
 * @file contents js for inline_comments_extra module
 */

(function($) {
  Drupal.behaviors.open_question_inline_comments = {
    attach: function(context, settings) {
      // inline comments behavior
      $('a.comment-link').mousedown(function() {
        $(this).click();
        $(this).parent().addClass('hidden');
        // insert comment form after list of comments
        var comments = $(this).parents('.views-row').find('.comment-group');
        $(this).parents('.views-row').find('.comment-form').insertAfter(comments);
      });
      $('.comment-form').find('.form-submit').click(function() {
        $(this).parents('.views-row').find('.views-inline-comment-field').removeClass('hidden').find('.comment-link').click();
      });
      // hide comments form
      $('.comment-cancel').click(function() {
        var nid = parseInt($(this).attr('id').replace('comment-form-hide-', ''), 10);
        $('#comment-form-show-' + nid).removeClass('hidden');
        $(this).parents('.views-row').find('.formcloselink').trigger('click');
      });
    }
  };
})(jQuery);
