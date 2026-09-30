# =======================================================
#                       LIBRARIES                       
# =======================================================

add_library(event_listener
    core/event_listener.cpp
    core/event_listener.hpp

    core/log_types.hpp
)

add_library(xml_manager
    core/xml_manager.cpp
    core/xml_manager.hpp

    core/log_types.hpp
)

add_library(database
    libs/database/database_connection.cpp
    core/sqlite_manager.cpp
    libs/database/database_connection.hpp
    core//sqlite_manager.hpp
)

# =======================================================

add_executable (windows-event-log-collector main.cpp)

# =======================================================
#                          HEADERS
# =======================================================

target_include_directories(event_listener
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/core
)

target_include_directories(xml_manager
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/core
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/external/pugixml/src
)

target_include_directories(database
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/core
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/external/sqlite3
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/database
)

target_link_libraries(windows-event-log-collector 
    PRIVATE
        event_listener
        xml_manager
        database
        wevtapi   
)

# =======================================================
#                          TESTS
# =======================================================