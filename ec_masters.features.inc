<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function ec_masters_ctools_plugin_api() {
  module_load_include('inc', 'ec_masters', 'ec_masters.defaults');
  $args = func_get_args();
  return call_user_func_array('_ec_masters_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_feeds_importer_default().
 */
function ec_masters_feeds_importer_default() {
  module_load_include('inc', 'ec_masters', 'ec_masters.defaults');
  $args = func_get_args();
  return call_user_func_array('_ec_masters_feeds_importer_default', $args);
}

/**
 * Implementation of hook_node_info().
 */
function ec_masters_node_info() {
  module_load_include('inc', 'ec_masters', 'ec_masters.features.node');
  $args = func_get_args();
  return call_user_func_array('_ec_masters_node_info', $args);
}
