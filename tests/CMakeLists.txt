project(p3signals_tests)

set(
	p3signals_tests_HEADERS
        ${p3signals_tests_SOURCE_DIR}/make_delegate_test.hpp
)

set(
	p3signals_tests_SOURCES
	${p3signals_tests_SOURCE_DIR}/main.cpp
)

add_executable(p3signals_tests ${p3signals_tests_HEADERS} ${p3signals_tests_SOURCES})
target_link_libraries(p3signals_tests cppunit)

