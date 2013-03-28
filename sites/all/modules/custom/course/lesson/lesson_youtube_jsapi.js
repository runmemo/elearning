(function($) {
    Drupal.behaviors.lesson_questions = {
        attach: function(context, settings) {
            //Code borrowed from : http://stackoverflow.com/questions/7988476/listening-for-youtube-event-in-javascript-or-jquery/7988536#7988536

            function getFrameID(id) {
                var elem = document.getElementById(id);
                if (elem) {
                    if (/^iframe$/i.test(elem.tagName))
                        return id; //Frame, OK
                    // else: Look for frame
                    var elems = elem.getElementsByTagName("iframe");
                    if (!elems.length)
                        return null; //No iframe found, FAILURE
                    for (var i = 0; i < elems.length; i++) {
                        if (/^https?:\/\/(?:www\.)?youtube(?:-nocookie)?\.com(\/|$)/i.test(elems[i].src))
                            break;
                    }
                    elem = elems[i]; //The only, or the best iFrame
                    if (elem.id)
                        return elem.id; //Existing ID, return it
                    // else: Create a new ID
                    do { //Keep postfixing `-frame` until the ID is unique
                        id += "-frame";
                    } while (document.getElementById(id));
                    elem.id = id;
                    return id;
                }
                // If no element, return null.
                return null;
            }

            // Define YT_ready function.
            var YT_ready = (function() {
                var onReady_funcs = [], api_isReady = false;
                /* @param func function     Function to execute on ready
                 * @param func Boolean      If true, all qeued functions are executed
                 * @param b_before Boolean  If true, the func will added to the first
                 position in the queue*/
                return function(func, b_before) {
                    if (func === true) {
                        api_isReady = true;
                        while (onReady_funcs.length) {
                            // Removes the first func from the array, and execute func
                            onReady_funcs.shift()();
                        }
                    } else if (typeof func == "function") {
                        if (api_isReady)
                            func();
                        else
                            onReady_funcs[b_before ? "unshift" : "push"](func);
                    }
                }
            })();
            // This function will be called when the API is fully loaded
            window.onYouTubePlayerAPIReady = function() {
                YT_ready(true);
            }

            // Load YouTube Frame API
            var s = document.createElement("script");
            s.src = (location.protocol == 'https:' ? 'https' : 'http') + "://www.youtube.com/player_api";
            var before = document.getElementsByTagName("script")[0];
            before.parentNode.insertBefore(s, before);
            var player; //Define a player object, to enable later function calls, without
            // having to create a new class instance again.
            // Add function to execute when the API is ready
            YT_ready(function() {
                var frameID = getFrameID($(".media-youtube-player").attr('id'));
                if (frameID) { //If the frame exists
                    player = new YT.Player(frameID, {
                        events: {
                            "onStateChange": stopCycle
                        }
                    });
                }
            });

            function stopCycle(event) {
                if (event.data == YT.PlayerState.ENDED) {
                    window.location = $('.page-next').attr('href');
                }
            }
        }
    };
})(jQuery);
