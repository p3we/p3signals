project(p3signals_tests)

set(
	p3signals_tests_HEADERS
)

set(
	p3signals_tests_SOURCES
	${p3signals_tests_SOURCE_DIR}/main.cpp
)

add_executable(p3signals_tests ${p3signals_tests_HEADERS} ${p3signals_tests_SOURCES})


