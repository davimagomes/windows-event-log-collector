# =======================================================
#                       LIBRARIES                       
# =======================================================

add_library(event_listener
    libs/collector/event_listener.cpp
    libs/collector/event_listener.hpp

    core/log_types.hpp
)

add_library(database
    libs/database/database_connection.cpp
    libs/database/sqlite_manager.cpp
    libs/database/database_connection.hpp
    libs/database/sqlite_manager.hpp
)

# =======================================================

add_executable (windows-event-log-collector main.cpp)

# =======================================================
#                          HEADERS
# =======================================================

target_include_directories(event_listener
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/collector
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/core
)

target_include_directories(database
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/database
)

target_link_libraries(windows-event-log-collector 
    PRIVATE
        event_listener
        database
        wevtapi   
)

# =======================================================
#                          TESTS
# =======================================================