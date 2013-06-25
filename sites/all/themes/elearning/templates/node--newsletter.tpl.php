<?php
/**
 * @file node-newsletter.tpl.php
 * Template for newsletter nodes.
 *
 * All variables available in node.tpl.php
 */
?>
<div id="node-newsletter-wrapper">
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="node-newsletter-author-section grid-2 alpha omega">
      <div class="node-newsletter-created">
        <?php print $created_formatted; ?>
      </div>
      <div class="node-newsletter-picture-points">
        <?php print $user_picture; ?>
      </div>
    </div>

    <div class="node-newsletter-body grid-12 alpha omega">
      <?php if (isset($title)) : ?>
        <h1 class="title"><?php print $title ?></h1>
      <?php endif; ?>

      <div class="newsletter-body grid-12 alpha omega">
        <?php if (isset($content['body'])) print render($content['body']); ?>
        <?php if (isset($created_formatted)) : ?>
          <div class="node-author">
            <div class="label">
              <?php print t('Author'); ?>:
            </div>
            <?php print $author; ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
