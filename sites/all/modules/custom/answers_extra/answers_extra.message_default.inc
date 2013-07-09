<?php

/**
 * Implements hook_default_message_type().
 */
function answers_extra_default_message_type() {
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
    "message_text" : {
      "en" : [
        {
          "value" : "New answer for the question on [site:name].",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003ENew answer for the question on [site:name].\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser \\u003Ca href=\\u0022[message:field-message-answer:author:url:absolute]\\u0022\\u003E[message:field-message-answer:author:field_first_name]\\u0026nbsp;[message:field-message-answer:author:field_surname]\\u003C\\/a\\u003E\\u0026nbsp;added\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-question:url:absolute]#answer-[message:field-message-answer:nid]\\u0022\\u003Eanswer\\u003C\\/a\\u003E\\u0026nbsp;to this question: \\u0022\\u003Ca href=\\u0022[message:field-message-question:url:absolute]\\u0022\\u003E[message:field-message-question:title]\\u003C\\/a\\u003E\\u0022.\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser \\u003Ca href=\\u0022[message:field-message-answer:author:url:absolute]\\u0022\\u003E[message:field-message-answer:author:field_first_name]\\u00a0[message:field-message-answer:author:field_surname]\\u003C\\/a\\u003E\\u00a0added\\u00a0\\u003Ca href=\\u0022[message:field-message-question:url:absolute]#answer-[message:field-message-answer:nid]\\u0022\\u003Eanswer\\u003C\\/a\\u003E\\u00a0to this question: \\u0022\\u003Ca href=\\u0022[message:field-message-question:url:absolute]\\u0022\\u003E[message:field-message-question:title]\\u003C\\/a\\u003E\\u0022.\\u003C\\/p\\u003E\\n"
        }
      ],
      "ru" : [
        {
          "value" : "\\u041d\\u043e\\u0432\\u044b\\u0439 \\u043e\\u0442\\u0432\\u0435\\u0442 \\u043d\\u0430 \\u0432\\u043e\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 [site:name].",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E\\u041d\\u043e\\u0432\\u044b\\u0439 \\u043e\\u0442\\u0432\\u0435\\u0442 \\u043d\\u0430 \\u0432\\u043e\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 [site:name].\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003E\\u041f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044c \\u003Ca href=\\u0022[message:field-message-answer:author:url:absolute]\\u0022\\u003E[message:field-message-answer:author:field_first_name]\\u0026nbsp;[message:field-message-answer:author:field_surname]\\u003C\\/a\\u003E\\u0026nbsp;\\u0434\\u043e\\u0431\\u0430\\u0432\\u0438\\u043b\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-question:url:absolute]#answer-[message:field-message-answer:nid]\\u0022\\u003E\\u043e\\u0442\\u0432\\u0435\\u0442\\u003C\\/a\\u003E\\u0026nbsp;\\u043d\\u0430 \\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0438\\u0439 \\u0432\\u043e\\u043f\\u0440\\u043e\\u0441: \\u0022\\u003Ca href=\\u0022[message:field-message-question:url:absolute]\\u0022\\u003E[message:field-message-question:title]\\u003C\\/a\\u003E\\u0022.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u041f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044c \\u003Ca href=\\u0022[message:field-message-answer:author:url:absolute]\\u0022\\u003E[message:field-message-answer:author:field_first_name]\\u00a0[message:field-message-answer:author:field_surname]\\u003C\\/a\\u003E\\u00a0\\u0434\\u043e\\u0431\\u0430\\u0432\\u0438\\u043b\\u00a0\\u003Ca href=\\u0022[message:field-message-question:url:absolute]#answer-[message:field-message-answer:nid]\\u0022\\u003E\\u043e\\u0442\\u0432\\u0435\\u0442\\u003C\\/a\\u003E\\u00a0\\u043d\\u0430 \\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0438\\u0439 \\u0432\\u043e\\u043f\\u0440\\u043e\\u0441: \\u0022\\u003Ca href=\\u0022[message:field-message-question:url:absolute]\\u0022\\u003E[message:field-message-question:title]\\u003C\\/a\\u003E\\u0022.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}