set (ITF_LIST ./Itf/ProvisionsItf.h ./Itf/ProvisionItf.h)

add_library(ProvisionsCore STATIC Provisions.cpp Provisions.h Provision.cpp Provision.h ${ITF_LIST})

target_include_directories(ProvisionsCore PUBLIC ${ITF_LIST})

set_property(TARGET ProvisionsCore PROPERTY COMPILE_WARNING_AS_ERROR ON)

add_subdirectory(Tests)