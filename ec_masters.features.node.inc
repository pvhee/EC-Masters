<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _ec_masters_node_info() {
  $items = array(
    'ignore_feed' => array(
      'name' => t('Ignore Feed'),
      'module' => 'features',
      'description' => t('A content type that includes a feed that should be ignored. Will be populated by the "master" feed.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'master' => array(
      'name' => t('Master'),
      'module' => 'features',
      'description' => t('Use to add a new master site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
