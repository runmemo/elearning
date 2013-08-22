/* 
 * @file
 * newsfeed.js contains js for newsfeed module.
 */

(function($) {
  // Due to 'flagGlobalAfterLinkUpdate' event is trggered multiple times,
  // we have to use bind() method, unbind and rebind the event listener each time
  // the flag update event is fired.
  bindFlagUpdate();
  function bindFlagUpdate() {
    $(document).bind('flagGlobalAfterLinkUpdate', function(event, data) {
      var count = parseInt($('.js-newsfeed-unread-count').text(), 10);
      if (data.flagName === 'message_read' && data.flagStatus == 'flagged' && count > 0) {
        count--;
      }
      $('.js-newsfeed-unread-count').text(count);
      $(document).unbind();
      bindFlagUpdate();
      return false;
    });
  }

})(jQuery);