add_executable(satellite_tracker main.cpp)
message(STATUS "PROJECT_SOURCE_DIR Before = ${PROJECT_SOURCE_DIR}")
target_include_directories(satellite_tracker PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_compile_features(satellite_tracker PRIVATE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang|IntelLLVM")
    target_compile_options(satellite_tracker PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
elseif(MSVC)
    target_compile_options(satellite_tracker PRIVATE
        /W4
        /permissive-
    )
endif()
