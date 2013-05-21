(function($) {
  Drupal.behaviors.registration_button = {
    attach: function(context, settings) {
      //code borrowed from user_extra.js
      $('.course-user-register').click(function() {
        var modal = $('.ctools-common-modal-content');
        modal.addClass('ctools-modal-user-forms');
        $('.ctools-common-modal-content').addClass('ctools-modal-register-form');
      });
      function toggle_popup(element) {
        $('.form-item-' + element + ' .description').fadeToggle();
        $('.popup-' + element + '-arrow').fadeToggle();
      }
      // popup behaviour for register form
      $('.popup-mail').hover(function() {
        toggle_popup('mail');
      });
      $('.popup-pass').hover(function() {
        toggle_popup('pass');
      });
    }
  };
})(jQuery);
