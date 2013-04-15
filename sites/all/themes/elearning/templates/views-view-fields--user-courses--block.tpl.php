<?php
/**
 * @file
 * "User courses" view template to display "Continue" link and progress-bar.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php if ($row->course_progress == 0) $style = ' style="color: #565656"'; ?>
<div class="views-user-courses-links">
  <?php print $fields['title']->wrapper_prefix . $fields['title']->content . $fields['title']->wrapper_suffix; ?>
  <div class="views-field views-field-link-exit">
    <?php print $row->exit_link; ?>
  </div>
  <div class="views-field views-field-link-continue">
    <?php print $row->continue_link; ?>
  </div>
</div>
<div class="view-user-courses-progress-outer">
  <p<?php if (isset($style)) print $style; ?>><?php print $row->course_progress . '%' ?></p>
  <div class="view-user-courses-progress-inner" style="width: <?php print $row->course_progress . '%' ?>">
    <div class="view-user-courses-progress-gradient"></div>
  </div>
</div>
