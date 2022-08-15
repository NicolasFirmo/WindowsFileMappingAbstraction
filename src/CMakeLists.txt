string(TOLOWER ${PROJECT_NAME} ExecutableName)

file(GLOB_RECURSE "${ExecutableName}_SOURCES" RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)
list(REMOVE_ITEM ${ExecutableName}_SOURCES pch.h)

message(STATUS "${ExecutableName}_SOURCES: ${${ExecutableName}_SOURCES}")

add_executable(${ExecutableName} ${${ExecutableName}_SOURCES})
target_include_directories(${ExecutableName} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(supportsIPO)
	set_target_properties(${ExecutableName} PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

target_precompile_headers(${ExecutableName} PRIVATE pch.h)

set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${ExecutableName})