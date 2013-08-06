<?php

/**
 * Implements hook_default_message_type().
 */
function newsletter_default_message_type() {
  $items = array();
  $items['newsletter_notification'] = entity_import('message_type', '{
    "name" : "newsletter_notification",
    "description" : "Message type for notifying course blog subscribers about new post.",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : {
      "en" : [
        {
          "value" : "New post in course [message:field-course:title] blog on [site:name].",
          "format" : "plain_text",
          "safe_value" : "\u003Cp\u003ENew post in course [message:field-course:title] blog on [site:name].\u003C\/p\u003E\n"
        },
        {
          "value" : "\u003Cp\u003ENew announcement was added for [message:field-course:title]: \u0022\u003Ca href=\u0022[message:field-message-newsletter:url]\u0022\u003E[message:field-message-newsletter:title]\u003C\/a\u003E\u0022.\u003C\/p\u003E\n",
          "format" : "full_html",
          "safe_value" : "\u003Cp\u003ENew announcement was added for [message:field-course:title]: \u0022\u003Ca href=\u0022[message:field-message-newsletter:url]\u0022\u003E[message:field-message-newsletter:title]\u003C\/a\u003E\u0022.\u003C\/p\u003E\n"
        }
      ],
      "ru" : [
        {
          "value" : "\u041d\u043e\u0432\u0430\u044f \u0437\u0430\u043f\u0438\u0441\u044c \u0432 \u0431\u043b\u043e\u0433\u0435 \u043a\u0443\u0440\u0441\u0430 [message:field-course:title] \u043d\u0430 \u0441\u0430\u0439\u0442\u0435 [site:name].",
          "format" : "plain_text",
          "safe_value" : "\u003Cp\u003E\u041d\u043e\u0432\u0430\u044f \u0437\u0430\u043f\u0438\u0441\u044c \u0432 \u0431\u043b\u043e\u0433\u0435 \u043a\u0443\u0440\u0441\u0430 [message:field-course:title] \u043d\u0430 \u0441\u0430\u0439\u0442\u0435 [site:name].\u003C\/p\u003E\n"
        },
        {
          "value" : "\u003Cp\u003E\u0414\u043b\u044f \u043a\u0443\u0440\u0441\u0430 [message:field-course:title] \u0434\u043e\u0431\u0430\u0432\u043b\u0435\u043d\u043e \u043d\u043e\u0432\u043e\u0435 \u043e\u0431\u044a\u044f\u0432\u043b\u0435\u043d\u0438\u0435: \u0022\u003Ca href=\u0022[message:field-message-newsletter:url]\u0022\u003E[message:field-message-newsletter:title]\u003C\/a\u003E\u0022.\u003C\/p\u003E\r\n",
          "format" : "full_html",
          "safe_value" : "\u003Cp\u003E\u0414\u043b\u044f \u043a\u0443\u0440\u0441\u0430 [message:field-course:title] \u0434\u043e\u0431\u0430\u0432\u043b\u0435\u043d\u043e \u043d\u043e\u0432\u043e\u0435 \u043e\u0431\u044a\u044f\u0432\u043b\u0435\u043d\u0438\u0435: \u0022\u003Ca href=\u0022[message:field-message-newsletter:url]\u0022\u003E[message:field-message-newsletter:title]\u003C\/a\u003E\u0022.\u003C\/p\u003E\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}