<?php
/**
 * @file
 * subscriptions_question.features.mail_edit_features.inc
 */

/**
 * Implements hook_default_mail_edit_features().
 */
function subscriptions_question_default_mail_edit_features() {
  $mail_edit_features = array();

  // Exported mail edit: subscriptions_mail_node-reference-field-answer-question--en
  $mail_edit_features['subscriptions_mail_node-reference-field-answer-question--en'] = array(
    'id' => 'subscriptions_mail_node-reference-field-answer-question',
    'module' => 'subscriptions_mail',
    'mailkey' => 'node-reference-field-answer-question',
    'registry_description' => 'Notifications for <em class="placeholder">answer-&gt;question</em> reference subscriptions',
    'language' => 'en',
    'description' => 'Notifications for answers related to questions via reference',
    'subject' => '[[site:name]] [subs:type] new answer was added to the question: [current-user:name]: [node:title]',
    'body' => '{{MAIL@| Hello, [current-user:name].
|
| Your subscription on [site:name]
| notifies you of {{[subs:is-new]==0?:a new answer:
}}{{[subs:is-updated]#an updated post:
}}{{[subs:is-old]#new comments on:
}}|
}}{{![subs:is-published]#| ***** This post is unpublished! *****
}}{{![subs:category:tid]?:{{[subs:category:tid]==[subs:forum:tid]?:| Category: [subs:category:name]
}}}}{{![subs:forum:tid]?:| Forum: [subs:forum:name]
}}{{![node:author:name]?:| Author: [node:author:name]
}}| Title: [node:title]
{{![subs:terms:field_tags:count]?:| [subs:terms:field_tags:first:vocabulary:name]: {{[subs:terms:field_tags:count]#{{!!#0#, }}[subs:terms:field_tags:index:#0:name]}}
}}{{![subs:is-old]?&nbsp;
[node:body]:{{![subs:has-distinct-summary]?&nbsp;
[node:body]:| Summary:
&nbsp;
[node:summary]}}}}
| LINK: [node:url]
{{![subs:is-old]#{{!![subs:files:field_files:count]#| Attached files:
{{[subs:files:field_files:count]#| [subs:files:field_files:index:#0:url]
}}}}}}{{![subs:comments:count]?| ---------------------------------------------------
:|
| Comments: [subs:comments:count]
| ---------------------------------------------------
[subs:comments:join:
]
}}| Direct unsubscribe link ([subs:type]):
| [subs:unsubscribe-url]
{{MAIL@| This is an automated message. Please do NOT reply to the sender address!
| To manage your subscriptions go to
| [subs:manage-url]
}}',
    'subscriptions_comment_body' => '| {{[subs:is-new]?New:Updated}} {{[subs:is-published]?:UNPUBLISHED }}comment:
| Author: [comment:author:name]
| Title: [comment:title]
&nbsp;
[comment:body]
| LINK: [comment:url]
{{!![subs:files:field_files:count]#| Attached files:
{{[subs:files:field_files:count]#| [subs:files:field_files:index:#0:url]
}}}}| ---------------------------------------------------',
  );

  return $mail_edit_features;
}
