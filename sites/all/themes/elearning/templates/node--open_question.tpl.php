<?php
/**
 * @file node--open_question.tpl.php
 * Template for open question nodes.
 * 
 * Available variables:
 * - $user_picture: HTML, representing user's picture
 * - $title: node title
 * - $content: node content
 * 
 * All variables available in node.tpl.php
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="node-open-question-picture grid-1 alpha">
    <?php print $user_picture; ?>
  </div>
  <div class="node-open-question-body grid-10 omega">
    <?php if (isset($title)) : ?><h1><?php print $title ?></h1><?php endif; ?>
    <?php if (isset($content['field_question'])) print render($content['field_question']); ?>
  </div>
</div>
