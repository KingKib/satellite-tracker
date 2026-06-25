add_executable(satellite_tracker_tests test_main.cpp)

target_link_libraries(satellite_tracker_tests PRIVATE
    satellite_tracker_core
    Catch2::Catch2WithMain
)

add_test(NAME satellite_tracker_tests COMMAND satellite_tracker_tests)
