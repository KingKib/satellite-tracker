cmake_minimum_required(VERSION 3.20)
project(SatelliteTracker VERSION 0.1.0 LANGUAGES CXX) # Standard to use Pascal Case for project names.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_CONFIGURATION_TYPES) # Checks if the CMAKE_CONFIGURATION_TYPES variable is not set; indicates that the project is not using a multi-configuration generator.
    if(NOT CMAKE_BUILD_TYPE) # Checks if the CMAKE_BUILD_TYPE variable is not set; indicates that the user has not specified a build type.
        message(STATUS "No build type specified, defaulting to Release") # Displays a message of type STATUS to inform the user that the build type is being set to 'Release'.
        set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build" FORCE) # Sets the build type to "Release" and defines it as a cache variable 
                                                                                    # meaning that it shows up in CMakeCache.txt in gui tools with a description "choose the..."
                                                                                    # overrides the cache value during configuration
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS # Sets the allowed values for the CMAKE_BUILD_TYPE variable
            Debug 
            Release 
            MinSizeRel 
            RelWithDebInfo)
    endif()
endif()

add_subdirectory(src)
add_subdirectory(tests)
