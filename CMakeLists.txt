FILE(GLOB_RECURSE component_folders LIST_DIRECTORIES true ${CMAKE_SOURCE_DIR}/components/JBase/*)


SET(component_includes "")
SET(component_sources "")
SET(component_requires "")
FOREACH(child ${component_folders})
    IF(IS_DIRECTORY ${child})
        LIST(APPEND component_includes ${child})

        FILE(GLOB_RECURSE component_source ${child}/*.cpp)
        FOREACH(src ${component_source})
            LIST(APPEND component_sources ${src})
        ENDFOREACH()

        IF(EXISTS ${child}/reqs.txt)
            FILE(STRINGS ${child}/reqs.txt component_reqs)
            FOREACH(req ${component_reqs})
                LIST(APPEND component_requires ${req})
            ENDFOREACH()
            
        ENDIF()
    ENDIF()
ENDFOREACH()


idf_component_register(SRCS ${component_sources} INCLUDE_DIRS ${component_includes} REQUIRES ${component_requires})


