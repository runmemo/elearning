<?php

/**
 * @file
 * Overrides theme implementation to navigate books.
 *
 * @see book-navigation.tpl.php for the list of default available varialbes.
 *
 * Available variables:
 * - $node_title: Markup for the title of the current book page.
 *  
 * @see template_preprocess_book_navigation()
 * @see elearning_preprocess_book_navigation()
 *
 */
?>
<?php if ($tree || $has_links): ?>
  <div id="book-navigation-<?php print $book_id; ?>" class="book-navigation">
    <?php print $tree; ?>

    <?php if ($has_links): ?>
    <div class="page-links clearfix">
      <?php if ($prev_url): ?>
        <a href="<?php print $prev_url; ?>" class="page-previous" title="<?php print t('Go to previous page'); ?>"><?php print t('‹ ') . $prev_title; ?></a>
      <?php endif; ?>
      <?php if ($node_title): ?>
        <div class="page-title"><?php print $node_title; ?></div>
      <?php endif; ?> 
      <?php if ($next_url): ?>
        <a href="<?php print $next_url; ?>" class="page-next" title="<?php print t('Go to next page'); ?>"><?php print $next_title . t(' ›'); ?></a>
      <?php endif; ?>
    </div>
    <?php endif; ?>

  </div>
<?php endif; ?>
