add_library(database_lib
        ../../external/sqlite3/sqlite3.c
        ../../external/sqlite3/sqlite3.h

        src/database_connection.cpp
        src/sqlite_manager.cpp
        include/database_connection.hpp
        include/sqlite_manager.hpp
)

target_include_directories(database_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../../external/sqlite3      #SQLite Dependency 
)


