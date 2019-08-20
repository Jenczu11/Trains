
cmake_minimum_required(VERSION 3.4)
project(biblioteka)

set(SOURCE_FILES
        src/Bilet.cpp
        src/klasa1.cpp
        src/Osobowy.cpp
        src/Pasazer.cpp
        src/Pociag.cpp
        include/Pociag.h
        src/Pospieszny.cpp
        src/Stacja.cpp
        src/klasa2.cpp
        src/BiletType.cpp
        include/BiletType.h src/klasa3.cpp include/klasa3.h)

#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(biblioteka ${SOURCE_FILES})


target_include_directories(biblioteka PUBLIC include)

find_package(Boost 1.65 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

#Test PASAZER
set(PASAZER_TEST_SOURCES
        test/master.cpp
        test/PasazerTest.cpp
        src/Pasazer.cpp
        src/Bilet.cpp
        src/BiletType.cpp
        src/klasa1.cpp
        src/klasa2.cpp
        src/klasa3.cpp)
add_executable(Pasazer_test ${PASAZER_TEST_SOURCES})
target_link_libraries(Pasazer_test
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
add_test(Pasazer_test Pasazer_tester)
#TEST POCIAGI
set(POCIAGI_TEST_SOURCES
        test/master.cpp
        test/PociagiTest.cpp
        src/Pociag.cpp
        src/Pospieszny.cpp
        src/Osobowy.cpp
        src/Pasazer.cpp
        src/Bilet.cpp
        src/BiletType.cpp
        src/klasa1.cpp
        src/klasa2.cpp
        src/klasa3.cpp)
add_executable(Pociagi_test ${POCIAGI_TEST_SOURCES})
target_link_libraries(Pociagi_test
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
add_test(Pociagi_test Pociagi_tester)
#TestStacja
set(STACJE_TEST_SOURCES
        src/Stacja.cpp
        test/master.cpp
        test/StacjaTest.cpp
        src/Pociag.cpp
        src/Pospieszny.cpp
        src/Osobowy.cpp
        src/Pasazer.cpp
        src/Bilet.cpp
        src/BiletType.cpp
        src/klasa1.cpp
        src/klasa2.cpp
        src/klasa3.cpp)
add_executable(Stacje_test ${STACJE_TEST_SOURCES})
target_link_libraries(Stacje_test
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
add_test(Stacje_test Stacje_tester)
#Test all
set(SOURCE_TEST_FILES
        test/PociagiTest.cpp
        test/master.cpp
        test/StacjaTest.cpp
        #dodanie reszty plikow bo to be
        src/Bilet.cpp
        src/klasa1.cpp
        src/klasa2.cpp
        src/Osobowy.cpp
        src/Pasazer.cpp
        src/Pociag.cpp
        src/Pospieszny.cpp
        src/Stacja.cpp
        test/PasazerTest.cpp
        src/BiletType.cpp
        include/BiletType.h
        src/klasa3.cpp
        include/klasa3.h)
add_executable(TESTY ${SOURCE_TEST_FILES})

target_include_directories(TESTY PUBLIC include)

target_link_libraries(TESTY
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})


enable_testing()

add_test(NAME Test COMMAND TestProject
        --report_level=detailed
        --log_level=all
        --color_output=yes)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})