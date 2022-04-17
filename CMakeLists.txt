## cmake_minimum_required(VERSION <min>[...<max>] [FATAL_ERROR])
cmake_minimum_required(VERSION 3.0)

## project(<PROJECT-NAME> [<language-name>...]), generated two variable PROJECT_SOURCE_DIR,PROJECT_BINARY_DIR
project(zstring)

##nclude_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])
include_directories(
    inc
)

## add_library(<name> [STATIC | SHARED | MODULE] [EXCLUDE_FROM_ALL] [source1] [source2 ...])
add_library(${PROJECT_NAME} SHARED
    zstring.c
)

## add_executable(<name> [WIN32] [MACOSX_BUNDLE] [EXCLUDE_FROM_ALL] [source1] [source2 ...])
add_executable(${PROJECT_NAME}-test
    main.c
)

## target_link_libraries(<target> ... <item>... ...)
target_link_libraries(${PROJECT_NAME}-test
    zstring
)

## add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
# add_subdirectory(test_case)