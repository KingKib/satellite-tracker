add_executable(satellite_tracker main.cpp) # Creates an executable target named "satellite_tracker" from the source file "main.cpp".
target_include_directories(satellite_tracker PRIVATE 
    ${PROJECT_SOURCE_DIR}/include # Adds the directory "${PROJECT_BINARY_DIR}/generated/version.h" 
    ${PROJECT_BINARY_DIR}/include # to the list of include directories for the "satellite_tracker" target. 
)                                                          # The "PRIVATE" keyword indicates that this include directory is only used 
                                                           # for compiling the "satellite_tracker" target and is not propagated to targets 
                                                           # that link against it.
target_compile_features(satellite_tracker PRIVATE cxx_std_17) # Specifies that the "satellite_tracker" target requires C++17 features. 
                                                    
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang|IntelLLVM") # Checks if the C++ compiler being used is GNU, Clang, AppleClang, or IntelLLVM.
    target_compile_options(satellite_tracker PRIVATE # Adds compiler options to the "satellite_tracker" target.
        -Wpedantic
    )
elseif(MSVC) # Checks if the C++ compiler being used is Microsoft Visual C++ (MSVC).
    target_compile_options(satellite_tracker PRIVATE # Adds compiler options to the "satellite_tracker" target for MSVC.
        /W4
        /permissive-
    )
endif()
