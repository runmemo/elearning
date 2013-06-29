/* 
 * @file contents js for feedback process on open question review list.
 */

(function($) {
  Drupal.behaviors.answers_extra = {
    attach: function(context, settings) {

      // Hover tooltip on Answer edit link.
      $(".answer-form-edit")
        .mouseenter(function() {
          $(this).next(".description").show();
        })
        .mouseleave(function() {
          $(this).next(".description").hide();
        });
    }
  };

  // Override js provided by inline_comments to hide edit button.
  Drupal.behaviors.comment_reply = {
    attach: function(context, settings) {
      $('#comment-form', context).unbind('submit').bind('submit', function(e){
        var options = {};
        var row =  $(this).parents('.views-row');
        var editLink = row.find('.edit-button');
        editLink.show();
        options['slideDown'] = false;
        options['targetEle'] = $(this).parents('.views-row').find('.comment-group');
        $('#comment-form', context).ajaxPost(options, function(){
           Drupal.attachBehaviors();
        });
        e.preventDefault();
      });
    }
  };
  
  Drupal.behaviors.comment_load_comment_form = {
    attach: function(context, settings) {
      $('a.comment-link, context').unbind('click').bind('click', function(){
        var options = {};
         // open expanded comments if not expanded already
         var row =  $(this).parents('.views-row');
         var commentclick = row.find('.comment-click');
         var commentgroup = row.find('.comment-group');
         var reply = row.find('.comment-form');
         var editLink = row.find('.edit-button');
         editLink.hide();

         if(commentclick){
           console.log(commentclick.text());
          if(commentgroup.is(':hidden') || commentgroup.length == 0){
            if(commentclick.text()!= '0 Comments'){
              commentclick.click();
            }
            else {
              // 0 comments so add comment group div
              row.append("<div class='comment-group'></div>");
            }
          }
         }
         if(reply.length == 0 ) {
           options['targetEle'] = $(this).parents('.views-row').find('.comment-group');
           $(this).reply();
         }
         return false;
      });
    }
  };

  Drupal.behaviors.comment_form_close_link = {
    attach: function(context, settings) {
      $('a.formcloselink').click(function(e) {
        var row =  $(this).parents('.views-row');
        var editLink = row.find('.edit-button');
        editLink.show();
        var group =  $(this).parents('.comment-form');
        var thoseComments = new closeComments(group);
        thoseComments.slide();
        thoseComments.scrollerUp();
        group.remove();
        e.preventDefault();
      });
    }
  };

  function closeComments(group) {
    if(group) {
      this.group = group;
    }
    this.scroller = group.offset().top -150;
  }
  closeComments.prototype.slide = function(){
    $(this.group).slideUp('slow');
  };
  closeComments.prototype.scrollerUp = function(){
    $('html,body').animate({
      scrollTop: this.scroller
    },
    1000);
  };

})(jQuery);


