<?php
/**
 * @file
 * provides html for quiz stats shown in quiz tooltips
 *
 * variables:
 *	$quiz - Quiz Node
 *	$questions - Questions in quiz
 *	$score - Score result of test.
 *	$summary - 
 *	$rid - results id.
 *	$next_lesson - Link to next course item.
 *	$quiz_report_form - Quiz answers.
 *	$wrong_score - total wrong scores.
 */
?>

<?php  if (!empty($score['possible_score'])) : ?>
  <div id="quiz_score_possible">
    <span class="title"><?php print t('Test Result'); ?> </span>
    <div class="summary">
      <span class="correct">
        <?php print t('Correct: %num_correct', array('%num_correct' => $score['numeric_score'])) . ' / '; ?>
      </span>
      <span class="wrong">
        <?php print t('Wrong: %num_wrong', array('%num_wrong' => $wrong_score)); ?>
      </span>
    </div> 
  </div>
<?php endif; ?>

<?php print $quiz_report_form; ?>

<?php print $next_lesson; ?>
