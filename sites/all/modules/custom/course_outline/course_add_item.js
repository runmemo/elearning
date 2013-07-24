
(function($) {
  Drupal.behaviors.course_outline_item_add = {
    attach: function(context, settings) {
      $('#course-add-item-lesson').ajaxStart(function(){  
        $("#course-add-item-lesson .form-submit").attr("disabled", "disabled");
      });
      $('#course-add-item-lesson').ajaxStop(function(){  
        $("#course-add-item-lesson .form-submit").removeAttr("disabled");
      });
    }
  };
})(jQuery);
