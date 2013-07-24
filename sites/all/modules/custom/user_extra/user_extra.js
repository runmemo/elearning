/* 
 * @file contents js for upload picture form on user profile.
 */

(function($) {
  Drupal.behaviors.user_login_system_forms = {
    attach: function(context, settings) {
      if (Drupal.settings.user_forms && Drupal.settings.user_forms.class) {
        var modal = $('.ctools-common-modal-content');
        var _class = Drupal.settings.user_forms.class;
        if ($.isArray(_class)) {
          _class = _class[1];
        }
        modal.addClass('ctools-modal-user-forms');
        if (_class.length > 0) {
          modal.addClass(_class);
        } else {
          modal.addClass('ctools-modal-login-form');
        }
        $('.login-form-additional-link').click(function() {
          $('.ctools-common-modal-content').removeClass('ctools-modal-login-form').addClass('ctools-modal-register-form');
        });
      }
      function toggle_popup(element, name) {
        $(element).parents('.form-wrapper').find('.form-item-' + name + ' .description').fadeToggle();
        $(element).parents('.form-wrapper').find('.popup-' + name + '-arrow').fadeToggle();
      }
      // popup behaviour for register form
      $('.popup-mail').hover(function() {
        toggle_popup($(this), 'mail');
      });
      $('.popup-pass').hover(function() {
        toggle_popup($(this), 'pass');
      });
    }
  };
 
  Drupal.behaviors.user_profile_tabs = {
    attach: function(context, settings) {
      // if userpoints form is in use on "History" tab, activate this tab instead of default "My questions"
      function urlparam(names) {
        var result = 0;
        jQuery.each(names, function(index, item) {
          var results = new RegExp('[\\?&]' + item + '=([^&#]*)').exec(window.location.href);
          if (results) {
            result = 1;
            return false;
          }
        });
        return result;
      }
      var names = ['page', 'sort', 'order', 'history'];
      if (urlparam(names)) {
        window.location = $('a[href="#qt-user_profile_tab-ui-tabs3"]', context).attr('href');
      }
    }
  };
})(jQuery);
