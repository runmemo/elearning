<?php

/**
 * @file field--field-social-buttons.tpl.php
 * Default template implementation to display the value of a social buttons field.
 *
 *
 * @see template_preprocess_field()
 * @see theme_field()
 */
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>
</div>
