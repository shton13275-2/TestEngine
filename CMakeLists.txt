cmake_minimum_required(VERSION 3.24)

project(TestEngine
    VERSION 0.1.0
    DESCRIPTION "A cross-platform C++ rendering engine"
    LANGUAGES CXX
)

option(TESTENGINE_BUILD_TESTS "Build TestEngine tests" ON)

add_library(TestEngine STATIC
    Engine/src/Engine.cpp
)

add_library(TestEngine::TestEngine ALIAS TestEngine)

target_compile_features(TestEngine PUBLIC cxx_std_20)

target_include_directories(TestEngine
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Engine/include>
        $<INSTALL_INTERFACE:include>
)

if(MSVC)
    target_compile_options(TestEngine PRIVATE /W4 /permissive-)
else()
    target_compile_options(TestEngine PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(TESTENGINE_BUILD_TESTS AND NOT CMAKE_SYSTEM_NAME STREQUAL "iOS")
    enable_testing()

    add_executable(TestEngineTests
        Tests/EngineTests.cpp
    )

    target_link_libraries(TestEngineTests PRIVATE TestEngine::TestEngine)
    target_compile_features(TestEngineTests PRIVATE cxx_std_20)

    add_test(NAME TestEngineTests COMMAND TestEngineTests)
endif()
