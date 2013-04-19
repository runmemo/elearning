/* 
 * @file contents js for upload picture form on user profile.
 */

(function($) {
  Drupal.behaviors.user_profile_edit = {
    attach: function(context, settings) {
      // show/hide "Choose photo link"
      $('.user-profile-picture-edit').hover(
        function() {
          $('.user-picture-edit').show();
        },
        function() {
          $('.user-picture-edit').hide();
        }
      );
      // show form for user picture
      $('.user-picture-edit').click(function() {
        $('.upload-form-background').show();
        $('.upload-form-container').show();
      });
      // hide form for user picture
      function upload_form_hide() {
        $('.upload-form-background').hide();
        $('.upload-form-container').hide();
      }
      // hide form if user clicks submit button, close icon or just clicks outside the form
      $('.upload-form-background').click(function() {
        upload_form_hide();
      });
      $('.upload-form-close').click(function() {
        upload_form_hide();
      });
      $('.upload-form-submit-link').click(function() {
        upload_form_hide();
      });
      // submit upload form if user chooses picture
      $('#edit-file').change(function() {
        $('.upload-form-main-submit').trigger('mousedown');
      });
      // when hovering on inputs for uploading files or deletion, add class to
      // links, which are in front of them
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
