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
      // When hovering on inputs for uploading files or deletion, add class to
      // links, which are in front of them.
      $('input#edit-file').hover(
        function() {
          $('.upload-link').addClass('active');
        },
        function() {
          $('.upload-link').removeClass('active');
        });

      $('input#edit-delete').hover(
        function() {
          $('.remove-link').addClass('active');
        },
        function() {
          $('.remove-link').removeClass('active');
        });
    }
  };
})(jQuery);
