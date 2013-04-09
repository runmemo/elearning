/* 
 * @file contents js for "elearning" theme
 */

(function($) {
  Drupal.behaviors.user_profile_edit = {
    attach: function(context, settings) {
      $('.user-profile-picture').hover(
        function() {
          $('.user-picture-edit').show();
        },
        function() {
          $('.user-picture-edit').hide();
        }
      );
    }
  };
})(jQuery);
