cmake_minimum_required(VERSION 3.10)

add_compile_definitions(V8_COMPRESS_POINTERS)
add_compile_definitions(V8_31BIT_SMIS_ON_64BIT_ARCH)
add_compile_definitions(V8_REVERSE_JSARGS)

add_compile_options("-march=core-avx2" "-mtune=generic")

#Optimise for lldb in debug mode
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -glldb -O0")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -g3 -glldb -O3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")


# Name of the project (will be the name of the plugin)
project(addon)

# Force colored output (ninja as generator confuses clang/GNU)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options ("-fdiagnostics-color=always")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options ("-fcolor-diagnostics")
endif ()

#set(CMAKE_CXX_CLANG_TIDY "/home/testuser/dev/llvm-project/build/bin/clang-tidy;-checks=bugprone-*")


# Build a shared library named after the project from the files in `src/`
file(GLOB SOURCE_FILES "src/*.cc" "src/*.h")
add_library(addon SHARED ${SOURCE_FILES})

# Gives our library file a .node extension without any "lib" prefix
set_target_properties(
  addon PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED TRUE
  CXX_EXTENSIONS NO
  PREFIX ""
  SUFFIX ".node"
  POSITION_INDEPENDENT_CODE ON
)


# Essential include files to build a node addon,
# You should add this line in every CMake.js based project
target_include_directories(addon PRIVATE ${CMAKE_JS_INC})

# Essential library files to link to a node addon
# You should add this line in every CMake.js based project
target_link_libraries(addon ${CMAKE_JS_LIB})
