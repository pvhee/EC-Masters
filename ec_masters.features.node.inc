<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _ec_masters_node_info() {
  $items = array(
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
