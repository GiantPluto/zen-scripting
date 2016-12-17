cmake_minimum_required (VERSION 3.5)

# Using experimental C++ features, including c++14 and c++17.
set(CMAKE_CXX_FLAGS "-std=c++1z")

project(zenscripting)

# Don't build in this directory
# mkdir ../zen-scripting-build
# cd ../zen-scripting-build
# cmake ../zen-scripting
# make
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

find_package(Boost REQUIRED unit_test_framework)

include_directories("${PROJECT_SOURCE_DIR}/include")

set(SOURCES
  lib/I_ScriptEngine.cpp
  lib/I_ScriptingManager.cpp
  lib/script_type.cpp
)

set(UNUSED_SOURCES
  lib/ScriptingManager.cpp
)

set(HEADERS
  include/Zen/Scripting/Configuration.hpp
  include/Zen/Scripting/forward_declarations.hpp
  include/Zen/Scripting/I_ObjectHeap.hpp
  include/Zen/Scripting/I_Scriptable.hpp
  include/Zen/Scripting/I_ScriptableService.hpp
  include/Zen/Scripting/I_ScriptEngine.hpp
  include/Zen/Scripting/I_ScriptEngineFactory.hpp
  include/Zen/Scripting/I_ScriptingManager.hpp
  include/Zen/Scripting/I_ScriptMethod.hpp
  include/Zen/Scripting/I_ScriptModule.hpp
  include/Zen/Scripting/I_ScriptObject.hpp
  include/Zen/Scripting/I_ScriptType.hpp
  include/Zen/Scripting/I_ScriptWrapper.hpp
  include/Zen/Scripting/script_arity_conversion.hpp
  include/Zen/Scripting/script_convert_argument.hpp
  include/Zen/Scripting/script_dispatch_helper.hpp
  include/Zen/Scripting/script_method.hpp
  include/Zen/Scripting/script_module.hpp
  include/Zen/Scripting/script_module_impl.hpp
  include/Zen/Scripting/script_type.hpp
  include/Zen/Scripting/script_type_impl.hpp
  include/Zen/Scripting/script_type_interface.hpp
  include/Zen/Scripting/script_type_traits.hpp
  include/Zen/Scripting/Scripting.hpp
  include/Zen/Scripting/ScriptWrapper.hpp
)

set(UNUSED_HEADERS
)

add_definitions(-DZEN_PLUGIN_EXPORTS)
add_definitions(-DBOOST_TEST_DYN_LINK) 

add_library(zen-scripting ${SOURCES})

enable_testing()

set(TEST_SOURCES
  test/simple.cpp
)

add_executable(zen-scripting-tests ${TEST_SOURCES})

target_link_libraries(zen-scripting-tests zen-scripting
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_test(tests zen-scripting-tests)

install(TARGETS zen-scripting DESTINATION /usr/local/bin)
install(DIRECTORY include DESTINATION /usr/local)
