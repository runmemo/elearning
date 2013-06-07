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
  $items['question_answer_notification'] = entity_import('message_type', '{
    "name" : "question_answer_notification",
    "description" : "Message type for notifying question subscribers about new answer",
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
          "value" : "New answer for the question on [site:name].",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003ENew answer for the question on [site:name].\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser \\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u0026nbsp;[message:user:field_surname]\\u003C\\/a\\u003E\\u0026nbsp;added\\u0026nbsp;\\u003Ca href=\\u0022http:\\/\\/[message:field-message-question:url:absolute]#answer-[message:field-message-answer:nid]\\u0022\\u003Eanswer\\u003C\\/a\\u003E\\u0026nbsp;to this question: \\u0022\\u003Ca href=\\u0022http:\\/\\/[message:field-message-question:url:absolute]\\u0022\\u003E[message:field-message-question:title]\\u003C\\/a\\u003E\\u0022.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser \\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u00a0[message:user:field_surname]\\u003C\\/a\\u003E\\u00a0added\\u00a0\\u003Ca href=\\u0022http:\\/\\/[message:field-message-question:url:absolute]#answer-[message:field-message-answer:nid]\\u0022\\u003Eanswer\\u003C\\/a\\u003E\\u00a0to this question: \\u0022\\u003Ca href=\\u0022http:\\/\\/[message:field-message-question:url:absolute]\\u0022\\u003E[message:field-message-question:title]\\u003C\\/a\\u003E\\u0022.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
