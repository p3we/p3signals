project(p3signals_tests)

if(NOT CppUnit_FOUND)
set(CppUnit_INCLUDE_DIRS "")
set(CppUnit_LIBRARIES "cppunit")
endif()

set(
	p3signals_tests_HEADERS
        ${p3signals_tests_SOURCE_DIR}/make_delegate_test.hpp
        ${p3signals_tests_SOURCE_DIR}/make_slot_test.hpp
        ${p3signals_tests_SOURCE_DIR}/signals_test.hpp
)

set(
	p3signals_tests_SOURCES
	${p3signals_tests_SOURCE_DIR}/main.cpp
)

add_executable(p3signals_tests ${p3signals_tests_HEADERS} ${p3signals_tests_SOURCES})
target_include_directories(p3signals_tests PRIVATE ${CppUnit_INCLUDE_DIRS})
target_link_libraries(p3signals_tests ${CppUnit_LIBRARIES})
