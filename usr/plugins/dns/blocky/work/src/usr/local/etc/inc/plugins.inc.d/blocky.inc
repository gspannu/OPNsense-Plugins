<?php

/*
 * Copyright (C) 2024 Guru Pannu <opnsense@gurupannu.com>
 * All rights reserved.
 *
 */

function blocky_services()
{
    global $config;

    $services = array();

    if (isset($config['OPNsense']['blocky']['general']['enabled']) && $config['OPNsense']['blocky']['general']['enabled'] == 1  && $config['OPNsense']['blocky']['general']['primarydns'] == 1) {
        $services[] = array(
            'dns_ports' => ['53'],
            'description' => gettext('Blocky DNS'),
            'configd' => array(
                'restart' => array('blocky restart'),
                'start' => array('blocky start'),
                'stop' => array('blocky stop'),
            ),
            'name' => 'blocky',
            'pidfile' => '/var/run/blocky.pid',
        );
    }
    elseif (isset($config['OPNsense']['blocky']['general']['enabled']) && $config['OPNsense']['blocky']['general']['enabled'] == 1  && $config['OPNsense']['blocky']['general']['primarydns'] == 0) {
        $services[] = array(
            'description' => gettext('Blocky DNS'),
            'configd' => array(
                'restart' => array('blocky restart'),
                'start' => array('blocky start'),
                'stop' => array('blocky stop'),
            ),
            'name' => 'blocky',
            'pidfile' => '/var/run/blocky.pid',
        );
    }  

    return $services;
}
