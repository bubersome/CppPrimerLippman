# If necessary, use the RELATIVE flag, otherwise each source file may be listed
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
set(CMAKE_CXX_STANDARD 11)
file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc )
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I../1")
# file( GLOB APP_SOURCES ${CMAKE_SOURCE_DIR}/*.c )
# AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} APP_SOURCES)
foreach( testsourcefile ${APP_SOURCES} )
    # I used a simple string replace, to cut off .cpp.
    string( REPLACE ".cc" "" testname ${testsourcefile} )
    add_executable( ${testname} ${testsourcefile} )
    target_include_directories(${testname} PUBLIC
            ../1)


    set_target_properties(${testname} PROPERTIES LINKER_LANGUAGE CXX)
    if(OpenMP_CXX_FOUND)
        target_link_libraries(${testname} OpenMP::OpenMP_CXX)
    endif()
    install(TARGETS ${testname} DESTINATION "bin/data_structures")

endforeach( testsourcefile ${APP_SOURCES} )

#add_subdirectory(cll)
