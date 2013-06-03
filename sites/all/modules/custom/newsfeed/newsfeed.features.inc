<?php
/**
 * @file
 * newsfeed.features.inc
 */

/**
 * Implements hook_default_message_type().
 */
function newsfeed_default_message_type() {
  $items = array();
  $items['subscriptions_notification'] = entity_import('message_type', '{
    "name" : "subscriptions_notification",
    "description" : "Subscriptions notification",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "1",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E1\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
