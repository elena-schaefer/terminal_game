cmake_minimum_required(VERSION 3.23)

project(Terminal_Game)

add_executable(Terminal_Game)

target_sources(Terminal_Game
    PRIVATE
        src/main.cpp
)

target_link_libraries(Terminal_Game
    PRIVATE 
        Classes
        Configs
)

add_library(Classes)
add_library(Configs INTERFACE)

target_link_libraries(Classes
    PRIVATE
        Configs
)

target_sources(Classes
    PRIVATE 
        src/game.cpp
        src/map.cpp
        src/mapRenderer.cpp
        src/player.cpp
        
    PUBLIC 
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES 
            include/game.h
            include/map.h
            include/mapRenderer.h
            include/player.h
)

target_sources(Configs
    INTERFACE 
        FILE_SET HEADERS
        BASE_DIRS
            config
        FILES 
            config/symbol.hpp
)
