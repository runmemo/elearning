<?php

/**
 * @file
 * user_extra.taxonomy.inc
 */

/**
 * Provides default taxonomy vocabularies.
 */
function _user_extra_taxonomy_default_vocabularies() {
  return array(
    'age_group' => array(
      'name' => 'Age groups',
      'machine_name' => 'age_group',
      'description' => 'Age groups for user accounts.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
