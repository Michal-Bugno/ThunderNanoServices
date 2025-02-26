# If not stated otherwise in this file or this component's LICENSE file the
# following copyright and licenses apply:
#
# Copyright 2020 Metrological
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set(PLUGIN_NAME TestUtility)
set(MODULE_NAME ${NAMESPACE}${PLUGIN_NAME})

set(PLUGIN_TESTUTILITY_MODE "Local" CACHE STRING "Controls if the plugin should run in its own process, in process or remote")

# deprecated/legacy flags support
if(PLUGIN_TESTUTILITY_OUTOFPROCESS STREQUAL "false")
    set(PLUGIN_TESTUTILITY_MODE "Off" CACHE STRING "Process mode"  FORCE)
    unset(PLUGIN_TESTUTILITY_OUTOFPROCESS CACHE)
endif()

find_package(${NAMESPACE}Plugins REQUIRED)
find_package(${NAMESPACE}Definitions REQUIRED)
find_package(CompileSettingsDebug CONFIG REQUIRED)

add_library(${MODULE_NAME} SHARED
        Module.cpp
        TestUtility.cpp
        TestUtilityImp.cpp
        TestUtilityJsonRpc.cpp
        CommandCore/TestCommandController.cpp
        Commands/Malloc.cpp
        Commands/Free.cpp
        Commands/Statm.cpp
        Commands/Crash.cpp
        Commands/CrashNTimes.cpp)

set_target_properties(${MODULE_NAME} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES)

target_link_libraries(${MODULE_NAME}
    PRIVATE
        CompileSettingsDebug::CompileSettingsDebug
        ${NAMESPACE}Plugins::${NAMESPACE}Plugins
        ${NAMESPACE}Definitions::${NAMESPACE}Definitions)

install(TARGETS ${MODULE_NAME}
    DESTINATION lib/${STORAGE_DIRECTORY}/plugins)

write_config(PLUGINS ${PLUGIN_NAME})
