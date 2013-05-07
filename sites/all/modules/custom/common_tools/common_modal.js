/**
 * Provide the HTML to create the modal dialog and behaviour for user lof=gin forms.
 */
(function($) {
  Drupal.theme.prototype.CommonModal = function() {
    var user_forms_class = '';
    if (Drupal.settings.user_forms.class) {
      var _class = Drupal.settings.user_forms.class;
      if ($.isArray(_class)) {
        _class = _class[0];
      }
      user_forms_class = ' ctools-modal-user-forms ' + _class;
    }
    var html = '';

    html += '<div id="ctools-modal" class="popups-box">';
    html += '  <div class="ctools-modal-content ctools-common-modal-content' + user_forms_class + '">';
    html += '    <div class="popups-container">';
    html += '      <div class="modal-header popups-title">';
    html += '        <span id="modal-title" class="modal-title"></span>';
    html += '        <span class="popups-close"><a class="close" href="#">' + Drupal.CTools.Modal.currentSettings.closeText + '</a></span>';
    html += '        <div class="clear-block"></div>';
    html += '      </div>';
    html += '      <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body"></div></div>';
    html += '    </div>';
    html += '  </div>';
    html += '</div>';

    return html;

  };
  Drupal.behaviors.user_login_system_forms = {
    attach: function(context, settings) {
      function toggle_popup(element) {
        $('.form-item-' + element + ' .description').fadeToggle();
        $('.popup-' + element + '-arrow').fadeToggle();
      }
      $('.messages').insertBefore('.form-actions');
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
