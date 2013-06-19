/* 
 * @file contents js for newsfeed module
 */

(function($) {
  Drupal.behaviors.newsfeed_notifications_count = {
    attach: function(context, settings) {
      $('.flag-message-read a.flag-action').click(function() {
        var count = parseInt($('#js-newsfeed-unread-count').text(), 10);
        if (count > 1) {
          count = count - 1;
        }
        $('#js-newsfeed-unread-count').text(count);
      });
    }
  };
})(jQuery);
