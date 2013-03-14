/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */




(function ($) {
  Drupal.behaviors.ch_bookoblock_accoridan = {
    attach: function(context,settings) {
      // if this node is in an iframe, show only the content
      jQuery('.block-ch-bookoblock').accordion({
        header: 'h3',
      });
    }
  }
})(jQuery)
