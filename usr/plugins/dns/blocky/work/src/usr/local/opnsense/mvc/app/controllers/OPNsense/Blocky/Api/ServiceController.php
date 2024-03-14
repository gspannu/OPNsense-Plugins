<?php

/*
 * Copyright (C) 2024 Guru Pannu <opnsense@gurupannu.com>
 * All rights reserved.
 */

namespace OPNsense\Blocky\Api;

use OPNsense\Base\ApiMutableServiceControllerBase;

class ServiceController extends ApiMutableServiceControllerBase
{
    protected static $internalServiceClass = '\OPNsense\Blocky\General';
    protected static $internalServiceTemplate = 'OPNsense/Blocky';
    protected static $internalServiceEnabled = 'enabled';
    protected static $internalServiceName = 'blocky';
}
