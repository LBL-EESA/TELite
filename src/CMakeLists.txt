add_library(TELite SimpleGrid.cpp Variable.cpp kdtree.cpp SimpleGridUtilities.cpp Announce.cpp)

file(GLOB_RECURSE FILES_MATCHING "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
install(FILES ${FILES_MATCHING}
    DESTINATION ${INCLUDE_PREFIX})

install(TARGETS TELite
    EXPORT TELite
    INCLUDES DESTINATION ${INCLUDE_PREFIX}
    ARCHIVE DESTINATION ${LIB_PREFIX}
    LIBRARY DESTINATION ${LIB_PREFIX})

install(EXPORT TELite
    DESTINATION ${LIB_PREFIX}
    FILE TELite.cmake
    EXPORT_LINK_INTERFACE_LIBRARIES)
