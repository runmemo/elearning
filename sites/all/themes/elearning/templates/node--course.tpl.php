<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
  </div>
</div>

<?php
  //print '<pre>';
  //var_dump($content['field_provider']['#object']->field_teacher['und']['0']['user']->referencing_entity->field_provider['und']['0']['node']->title);
 //print '</pre>';
 //$content['field_provider']['#object']['title'] 
?>

<div id="first-row">
	<div id="info-provider">
		<div class="field-name-field-logotype">
			<img id="imgplaceholder" src="<?php print image_style_url('logo-school', $content['field_provider']['#object']->field_teacher['und']['0']['user']->referencing_entity->field_provider['und']['0']['node']->field_logotype['und']['0']['uri']); ?>">
		</div>
	
		<div id="info-school">
			<div id="name-course">
				<div class="title-node" id="course"><?php echo render($content['title_field']);?></div>
			</div>
			
			<div class="title-node" id="provider"><?php print $content['field_provider']['#object']->field_teacher['und']['0']['user']->referencing_entity->field_provider['und']['0']['node']->title; ?>
			</div>
		</div>
	</div>
</div>

<div id="second-row">
	<div id="info-teacher">
	<?php echo render($content['field_teacher']);?>
	</div>
	<div id="video-course">
	<?php echo render($content['field_video']);?>
	</div>
</div>	

<?php echo render($content['field_discipline']);?>

<?php echo render($content['body']);?>