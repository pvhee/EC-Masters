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
  else if ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
  else if ($module == "strongarm" && $api == "strongarm") {
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

/**
 * Helper to implementation of hook_openlayers_presets().
 */
function _ec_masters_openlayers_presets() {
  $export = array();
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'master_map';
  $openlayers_presets->title = 'Master Map';
  $openlayers_presets->description = 'Master map showing the partners linked to their masters';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => '',
    'css_path' => '',
    'proxy_host' => '',
    'center' => array(
      'initial' => array(
        'centerpoint' => '16.699218749333, 58.077876266337',
        'zoom' => '3',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_popup' => array(),
      'openlayers_behavior_tooltip' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(),
      'openlayers_behavior_navigation' => array(),
      'openlayers_behavior_panzoombar' => array(),
    ),
    'default_layer' => 'google_physical',
    'layers' => array(
      'google_physical' => 'google_physical',
      'masters_map_openlayers_1' => 'masters_map_openlayers_1',
    ),
    'layer_styles' => array(),
    'layer_activated' => array(
      'masters_map_openlayers_1' => 'masters_map_openlayers_1',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
    'options' => NULL,
  );

  $export['master_map'] = $openlayers_presets;
  return $export;
}
