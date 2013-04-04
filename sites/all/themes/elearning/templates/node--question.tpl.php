<?php
/**
 * @file node-question.tpl.php
 * Template for question nodes.
 *
 * All variables available in node.tpl.php
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="node-question-title-section">
    <div class="node-question-picture-points">
      <?php print $user_picture; ?>
      <div class="author-points">
        <?php print $userpoints_count; ?>
      </div>
    </div>
    <?php if (isset($title)) : ?><h1><?php print $title ?></h1><?php endif; ?>
  </div>
  <div class="node-question-body grid-11 alpha omega">
    <?php if (isset($content['field_rating_widget'])) print render($content['field_rating_widget']); ?>
    <div class="question-body">
      <?php if (isset($content['body'])) print render($content['body']); ?>
      <?php if (isset($created_formatted)) : ?>
        <div class="node-supplementary-wrapper">
          <div class="node-supplementary">
            <?php print $created_formatted; ?>
          </div>
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>
