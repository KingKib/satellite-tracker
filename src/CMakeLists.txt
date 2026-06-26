add_library(satellite_tracker_core Satellite.cpp TLEParser.cpp Propagator.cpp)

add_executable(satellite_tracker main.cpp)
target_link_libraries(satellite_tracker PRIVATE satellite_tracker_core)

target_include_directories(satellite_tracker_core PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}/include
)
                 
target_compile_features(satellite_tracker_core PUBLIC cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang|IntelLLVM") 
    target_compile_options(satellite_tracker PRIVATE 
        -Wpedantic
    )
    target_compile_options(satellite_tracker_core PRIVATE 
        -Wpedantic
    )
elseif(MSVC)
    target_compile_options(satellite_tracker PRIVATE
        /W4
        /permissive-
    )
    target_compile_options(satellite_tracker_core PRIVATE
        /W4
        /permissive-
    )
endif()
