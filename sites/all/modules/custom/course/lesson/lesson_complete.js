(function($){
 
 
  /**
   * Define a custom ajax action not associated with an element.
   */
 
  /**
   * Define a point to trigger our custom actions. e.g. on page load.
   */
  $(document).ready(function() {
    var custom_settings = {}; alert(Drupal.settings.toSource());
    var base_path = Drupal.settings.basePath;
    custom_settings.url = base_path+'/lesson/video-complete/ajax/';
    custom_settings.event = 'onload';
    custom_settings.keypress = false;
    custom_settings.prevent = false;
    Drupal.ajax['custom_ajax_action'] = new Drupal.ajax(null, $(document.body), custom_settings);
    Drupal.ajax['custom_ajax_action'].specifiedResponse();
  });
 
})(jQuery);               
