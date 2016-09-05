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
  lib/I_ObjectReference.cpp
  lib/I_ScriptableService.cpp
  lib/I_ScriptableType.cpp
  lib/I_PluginManager.cpp)

set(HEADERS
  include/Zen/Scripting/Configuration.hpp
  include/Zen/Scripting/forward_declarations.hpp
  include/Zen/Scripting/I_ObjectHeap.hpp
  include/Zen/Scripting/I_ObjectReference.hpp
  include/Zen/Scripting/I_ScriptableService.hpp
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
