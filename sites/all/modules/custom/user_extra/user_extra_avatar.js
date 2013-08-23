/* 
 * @file contents js for upload picture form on user profile.
 */

(function($) {
  Drupal.behaviors.user_profile_picture_edit = {
    attach: function(context, settings) {
      // Show/hide "Choose photo" link.
      $('.js-avatar').hover(
        function() {
          $('.js-avatar-edit').show();
        },
        function() {
          $('.js-avatar-edit').hide();
        }
      );
      // Show form for user picture.
      $('.js-avatar-edit').click(function() {
        $('.js-modal').show();
      });
      // Hide form for user picture.
      function upload_form_hide() {
        $('.js-modal').hide();
        $('#js-user-avatar').html($('#upload-form-picture .default-avatar').html());
      }
      // Hide form if user clicks submit button, close icon or just clicks outside the form.
      $('.js-modal-out, .popups-close, .upload-form-submit-link').click(function() {
        upload_form_hide();
      });
      // Submit upload form if user chooses picture.
      $('#edit-file').change(function() {
        $('.upload-form-main-submit').trigger('mousedown');
      });
     
      // Open file browser on link click.
      $('.upload-link').click(function() {
        $('input[type=file]').click();
        return false;
      });
      // Remove photo on link click.
      $('.remove-link').click(function() {
        $('#edit-delete').mousedown();
        return false;
      });
    }
  };
})(jQuery);
