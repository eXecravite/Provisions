add_executable(Provisions main.cpp)

target_link_libraries(Provisions PUBLIC ProvisionsCore)

set_property(TARGET Provisions PROPERTY COMPILE_WARNING_AS_ERROR ON)
