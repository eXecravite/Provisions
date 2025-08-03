cmake_minimum_required(VERSION 3.15...4.0)

project(Provisions VERSION 1.0
                  DESCRIPTION "An application for managing provisions"
                  LANGUAGES CXX)

include(CTest)
include(FetchContent)

FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.9.0)
FetchContent_MakeAvailable(catch)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)

set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY
  clang-tidy;
  -warnings-as-errors=*;)

add_subdirectory(cmd)
add_subdirectory(ProvisionsCore)



