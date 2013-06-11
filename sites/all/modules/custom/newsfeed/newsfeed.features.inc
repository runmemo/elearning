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
  $items['answer_feedback_notification'] = entity_import('message_type', '{
    "name" : "answer_feedback_notification",
    "description" : "Answer Feedback Notification",
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
          "value" : "New feedback to your answer on [site:name].",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003ENew feedback to your answer on [site:name].\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser\\u0026nbsp;\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u0026nbsp;[message:user:field_surname]\\u003C\\/a\\u003E\\u0026nbsp;added\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#feedback-[message:field-message-feedback:nid]\\u0022\\u003Efeedback\\u003C\\/a\\u003E\\u0026nbsp;to\\u0026nbsp;your\\u0026nbsp;answer\\u0026nbsp;to\\u0026nbsp;this\\u0026nbsp;question:\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]\\u0022\\u003E[message:field-message-feedback:field-open-question-answer:field-open-question:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser\\u00a0\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u00a0[message:user:field_surname]\\u003C\\/a\\u003E\\u00a0added\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#feedback-[message:field-message-feedback:nid]\\u0022\\u003Efeedback\\u003C\\/a\\u003E\\u00a0to\\u00a0your\\u00a0answer\\u00a0to\\u00a0this\\u00a0question:\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]\\u0022\\u003E[message:field-message-feedback:field-open-question-answer:field-open-question:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ],
      "ru" : [
        {
          "value" : "\\u041d\\u043e\\u0432\\u044b\\u0439 \\u043e\\u0442\\u0437\\u044b\\u0432 \\u043d\\u0430 \\u0432\\u0430\\u0448 \\u043e\\u0442\\u0432\\u0435\\u0442 \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435 [site:name].",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E\\u041d\\u043e\\u0432\\u044b\\u0439 \\u043e\\u0442\\u0437\\u044b\\u0432 \\u043d\\u0430 \\u0432\\u0430\\u0448 \\u043e\\u0442\\u0432\\u0435\\u0442 \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435 [site:name].\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003E\\u041f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044c\\u0026nbsp;\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u0026nbsp;[message:user:field_surname]\\u003C\\/a\\u003E\\u0026nbsp;\\u043e\\u0441\\u0442\\u0430\\u0432\\u0438\\u043b\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#feedback-[message:field-message-feedback:nid]\\u0022\\u003E\\u043e\\u0442\\u0437\\u044b\\u0432\\u003C\\/a\\u003E\\u0026nbsp;\\u043d\\u0430\\u0026nbsp;\\u0432\\u0430\\u0448\\u0026nbsp;\\u043e\\u0442\\u0432\\u0435\\u0442\\u0026nbsp;\\u043d\\u0430\\u0026nbsp;\\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0438\\u0439\\u0026nbsp;\\u0432\\u043e\\u043f\\u0440\\u043e\\u0441:\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]\\u0022\\u003E[message:field-message-feedback:field-open-question-answer:field-open-question:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u041f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044c\\u00a0\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u00a0[message:user:field_surname]\\u003C\\/a\\u003E\\u00a0\\u043e\\u0441\\u0442\\u0430\\u0432\\u0438\\u043b\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#feedback-[message:field-message-feedback:nid]\\u0022\\u003E\\u043e\\u0442\\u0437\\u044b\\u0432\\u003C\\/a\\u003E\\u00a0\\u043d\\u0430\\u00a0\\u0432\\u0430\\u0448\\u00a0\\u043e\\u0442\\u0432\\u0435\\u0442\\u00a0\\u043d\\u0430\\u00a0\\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0438\\u0439\\u00a0\\u0432\\u043e\\u043f\\u0440\\u043e\\u0441:\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]\\u0022\\u003E[message:field-message-feedback:field-open-question-answer:field-open-question:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['oqaf_author_comment_notification'] = entity_import('message_type', '{
    "name" : "oqaf_author_comment_notification",
    "description" : "Open Question Answer Feedback Author Comment Notification",
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
          "value" : "New comment to the feedback to your answer on [site:name].",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003ENew comment to the feedback to your answer on [site:name].\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser\\u0026nbsp;\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u0026nbsp;[message:user:field_surname]\\u003C\\/a\\u003E\\u0026nbsp;added\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#comment-[message:field-message-comment:cid]\\u0022\\u003Ecomment\\u003C\\/a\\u003E\\u0026nbsp;to\\u0026nbsp;this\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#feedback-[message:field-message-feedback:nid]\\u0022\\u003Efeedback\\u003C\\/a\\u003E\\u0026nbsp;to\\u0026nbsp;your\\u0026nbsp;answer\\u0026nbsp;to\\u0026nbsp;this\\u0026nbsp;question:\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]\\u0022\\u003E[message:field-message-feedback:field-open-question-answer:field-open-question:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser\\u00a0\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u00a0[message:user:field_surname]\\u003C\\/a\\u003E\\u00a0added\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#comment-[message:field-message-comment:cid]\\u0022\\u003Ecomment\\u003C\\/a\\u003E\\u00a0to\\u00a0this\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#feedback-[message:field-message-feedback:nid]\\u0022\\u003Efeedback\\u003C\\/a\\u003E\\u00a0to\\u00a0your\\u00a0answer\\u00a0to\\u00a0this\\u00a0question:\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]\\u0022\\u003E[message:field-message-feedback:field-open-question-answer:field-open-question:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ],
      "ru" : [
        {
          "value" : "\\u041d\\u043e\\u0432\\u044b\\u0439 \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0439 \\u043a \\u043e\\u0442\\u0437\\u044b\\u0432\\u0443 \\u043d\\u0430 \\u0412\\u0430\\u0448 \\u043e\\u0442\\u0432\\u0435\\u0442 \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435 [site:name].",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E\\u041d\\u043e\\u0432\\u044b\\u0439 \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0439 \\u043a \\u043e\\u0442\\u0437\\u044b\\u0432\\u0443 \\u043d\\u0430 \\u0412\\u0430\\u0448 \\u043e\\u0442\\u0432\\u0435\\u0442 \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435 [site:name].\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003E\\u041f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044c\\u0026nbsp;\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u0026nbsp;[message:user:field_surname]\\u003C\\/a\\u003E\\u0026nbsp;\\u043e\\u0441\\u0442\\u0430\\u0432\\u0438\\u043b\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#comment-[message:field-message-comment:cid]\\u0022\\u003E\\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0439\\u003C\\/a\\u003E\\u0026nbsp;\\u043a\\u0026nbsp;\\u044d\\u0442\\u043e\\u043c\\u0443\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#feedback-[message:field-message-feedback:nid]\\u0022\\u003E\\u043e\\u0442\\u0437\\u044b\\u0432\\u0443\\u003C\\/a\\u003E\\u0026nbsp;\\u043d\\u0430\\u0026nbsp;\\u0412\\u0430\\u0448\\u0026nbsp;\\u043e\\u0442\\u0432\\u0435\\u0442\\u0026nbsp;\\u043d\\u0430\\u0026nbsp;\\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0438\\u0439\\u0026nbsp;\\u0432\\u043e\\u043f\\u0440\\u043e\\u0441:\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]\\u0022\\u003E[message:field-message-feedback:field-open-question-answer:field-open-question:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u041f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044c\\u00a0\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u00a0[message:user:field_surname]\\u003C\\/a\\u003E\\u00a0\\u043e\\u0441\\u0442\\u0430\\u0432\\u0438\\u043b\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#comment-[message:field-message-comment:cid]\\u0022\\u003E\\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0439\\u003C\\/a\\u003E\\u00a0\\u043a\\u00a0\\u044d\\u0442\\u043e\\u043c\\u0443\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#feedback-[message:field-message-feedback:nid]\\u0022\\u003E\\u043e\\u0442\\u0437\\u044b\\u0432\\u0443\\u003C\\/a\\u003E\\u00a0\\u043d\\u0430\\u00a0\\u0412\\u0430\\u0448\\u00a0\\u043e\\u0442\\u0432\\u0435\\u0442\\u00a0\\u043d\\u0430\\u00a0\\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0438\\u0439\\u00a0\\u0432\\u043e\\u043f\\u0440\\u043e\\u0441:\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]\\u0022\\u003E[message:field-message-feedback:field-open-question-answer:field-open-question:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['oqaf_reviewer_comment_notification'] = entity_import('message_type', '{
    "name" : "oqaf_reviewer_comment_notification",
    "description" : "Open Question Answer Feedback Reviewer Comment Notification",
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
          "value" : "New comment to your feedback on [site:name]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003ENew comment to your feedback on [site:name]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser\\u0026nbsp;\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u0026nbsp;[message:user:field_surname]\\u003C\\/a\\u003E\\u0026nbsp;added\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]?comment=[message:field-message-comment:cid]\\u0022\\u003Ecomment\\u003C\\/a\\u003E\\u0026nbsp;to\\u0026nbsp;your\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#review-[message:field-message-feedback:nid]\\u0022\\u003Efeedback\\u003C\\/a\\u003E\\u0026nbsp;to\\u0026nbsp;this\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#answer-[message:field-message-feedback:field-open-question-answer:nid]\\u0022\\u003Eanswer\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser\\u00a0\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u00a0[message:user:field_surname]\\u003C\\/a\\u003E\\u00a0added\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]?comment=[message:field-message-comment:cid]\\u0022\\u003Ecomment\\u003C\\/a\\u003E\\u00a0to\\u00a0your\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#review-[message:field-message-feedback:nid]\\u0022\\u003Efeedback\\u003C\\/a\\u003E\\u00a0to\\u00a0this\\u00a0\\u003Ca href=\\u0022[message:field-message-feedback:field-open-question-answer:field-open-question:url]#answer-[message:field-message-feedback:field-open-question-answer:nid]\\u0022\\u003Eanswer\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
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
          "value" : "\\u003Cp\\u003EUser \\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u0026nbsp;[message:user:field_surname]\\u003C\\/a\\u003E\\u0026nbsp;added\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-question:url:absolute]#answer-[message:field-message-answer:nid]\\u0022\\u003Eanswer\\u003C\\/a\\u003E\\u0026nbsp;to this question: \\u0022\\u003Ca href=\\u0022[message:field-message-question:url:absolute]\\u0022\\u003E[message:field-message-question:title]\\u003C\\/a\\u003E\\u0022.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser \\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u00a0[message:user:field_surname]\\u003C\\/a\\u003E\\u00a0added\\u00a0\\u003Ca href=\\u0022[message:field-message-question:url:absolute]#answer-[message:field-message-answer:nid]\\u0022\\u003Eanswer\\u003C\\/a\\u003E\\u00a0to this question: \\u0022\\u003Ca href=\\u0022[message:field-message-question:url:absolute]\\u0022\\u003E[message:field-message-question:title]\\u003C\\/a\\u003E\\u0022.\\u003C\\/p\\u003E\\n"
        }
      ],
      "ru" : [
        {
          "value" : "\\u041d\\u043e\\u0432\\u044b\\u0439 \\u043e\\u0442\\u0432\\u0435\\u0442 \\u043d\\u0430 \\u0432\\u043e\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 [site:name].",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E\\u041d\\u043e\\u0432\\u044b\\u0439 \\u043e\\u0442\\u0432\\u0435\\u0442 \\u043d\\u0430 \\u0432\\u043e\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 [site:name].\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003E\\u041f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044c \\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u0026nbsp;[message:user:field_surname]\\u003C\\/a\\u003E\\u0026nbsp;\\u0434\\u043e\\u0431\\u0430\\u0432\\u0438\\u043b\\u0026nbsp;\\u003Ca href=\\u0022[message:field-message-question:url:absolute]#answer-[message:field-message-answer:nid]\\u0022\\u003E\\u043e\\u0442\\u0432\\u0435\\u0442\\u003C\\/a\\u003E\\u0026nbsp;\\u043d\\u0430 \\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0438\\u0439 \\u0432\\u043e\\u043f\\u0440\\u043e\\u0441: \\u0022\\u003Ca href=\\u0022[message:field-message-question:url:absolute]\\u0022\\u003E[message:field-message-question:title]\\u003C\\/a\\u003E\\u0022.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u041f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044c \\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:field-name]\\u00a0[message:user:field_surname]\\u003C\\/a\\u003E\\u00a0\\u0434\\u043e\\u0431\\u0430\\u0432\\u0438\\u043b\\u00a0\\u003Ca href=\\u0022[message:field-message-question:url:absolute]#answer-[message:field-message-answer:nid]\\u0022\\u003E\\u043e\\u0442\\u0432\\u0435\\u0442\\u003C\\/a\\u003E\\u00a0\\u043d\\u0430 \\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0438\\u0439 \\u0432\\u043e\\u043f\\u0440\\u043e\\u0441: \\u0022\\u003Ca href=\\u0022[message:field-message-question:url:absolute]\\u0022\\u003E[message:field-message-question:title]\\u003C\\/a\\u003E\\u0022.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
