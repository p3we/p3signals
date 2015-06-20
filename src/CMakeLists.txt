project(p3signals_prj)

set(
	p3signals_prj_HEADERS
	${p3signals_prj_SOURCE_DIR}/include/p3delegate.hpp
        ${p3signals_prj_SOURCE_DIR}/include/p3signals.hpp
)

set(
	p3signals_prj_SOURCES
)

add_custom_target(p3signals SOURCES ${p3signals_prj_HEADERS} ${p3signals_prj_SOURCES})

