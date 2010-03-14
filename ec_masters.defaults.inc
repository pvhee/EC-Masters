<?php

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _ec_masters_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_feeds_importer_default().
 */
function _ec_masters_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ignore';
  $feeds_importer->config = array(
    'name' => 'Ignore',
    'description' => 'A feed that should be ignored.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'story',
        'update_existing' => 0,
        'expire' => -1,
        'mappings' => array(),
      ),
    ),
    'content_type' => 'ignore_feed',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 0,
  );

  $export['ignore'] = $feeds_importer;
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'master';
  $feeds_importer->config = array(
    'name' => 'Master',
    'description' => 'Import OPML from a Master Template',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsOPMLMultiParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsMultiFeedNodeProcessor',
      'config' => array(
        'content_type' => 'ignore_feed',
        'update_existing' => 1,
        'expire' => '-1',
        'mappings' => array(
          '0' => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          '1' => array(
            'source' => 'xmlurl',
            'target' => 'url',
            'unique' => 1,
          ),
          '2' => array(
            'source' => 'type',
            'target' => 'type',
            'unique' => FALSE,
          ),
        ),
      ),
    ),
    'content_type' => 'master',
    'update' => 0,
    'import_period' => '3600',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['master'] = $feeds_importer;
  return $export;
}
