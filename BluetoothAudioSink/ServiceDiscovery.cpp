/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2021 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Module.h"

#include "ServiceDiscovery.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(A2DP::ServiceDiscovery::AudioService::type)
    { A2DP::ServiceDiscovery::AudioService::UNKNOWN, _TXT("Unknown") },
    { A2DP::ServiceDiscovery::AudioService::SOURCE, _TXT("Source") },
    { A2DP::ServiceDiscovery::AudioService::SINK, _TXT("Sink") },
    { A2DP::ServiceDiscovery::AudioService::OTHER, _TXT("Other") },
ENUM_CONVERSION_END(A2DP::ServiceDiscovery::AudioService::type);

}
