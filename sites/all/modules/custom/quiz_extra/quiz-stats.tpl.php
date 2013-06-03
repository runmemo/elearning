<?php
/**
 * @file
 * provides html for quiz stats shown in quiz tooltips
 *
 * variables:
 * 	$stats - array of stats
 */
?>

<a class="quiz-stat-popup"></a>
<div id="quiz-stat-wrapper">
  <?php foreach($stats as $stat): ?>
    <div class="quiz-stat">
      <span class="stat-title"> <?php print $stat['title'] ?>: </span>
      <span class="stat-data"> <?php print $stat['data'] ?> </span>
    </div>
  <?php endforeach; ?>
</div> 
