add_executable(TestProvisionsCore ProvisionTest.cpp)

target_link_libraries(TestProvisionsCore PRIVATE ProvisionsCore Catch2::Catch2WithMain)

catch_discover_tests(TestProvisionsCore)

