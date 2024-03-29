/**
 * Avoid popups on mobile devices
 */
(function($) {
  Drupal.behaviors.common_tools = {
    attach: function(context, settings) {
      if( /Android|webOS|iPhone|iPad|iPod|BlackBerry/i.test(navigator.userAgent) ) {
        $( "a" ).each(function( index ) {
          if ($(this).hasClass('ctools-use-modal')) {
            $(this).removeClass('ctools-use-modal');
          }
        });
      }
      
      if($('#modalContent').length >= 1) {
        $('.absolute-messages-error').insertBefore('.ctools-modal-content .form-actions');
      }
    }
  };

})(jQuery);
