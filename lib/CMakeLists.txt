set(libName sharedmemlib)

file(GLOB_RECURSE "${libName}_SOURCES" RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)
list(REMOVE_ITEM ${libName}_SOURCES pch.h)

message(STATUS "${libName}_SOURCES: ${${libName}_SOURCES}")

add_library(${libName} STATIC ${${libName}_SOURCES})

target_include_directories(${libName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(supportsIPO)
	set_target_properties(${libName} PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

target_precompile_headers(${libName} PRIVATE pch.h)