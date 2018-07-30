project(XO_Lib)

set(HEADER_FILES
        vars.h
        player.h
        human.h
        computer.h
        board.h
        )

set(SOURCE_FILES
        player.cpp
        human.cpp
        computer.cpp
        board.cpp
        )

add_library(XO_Lib STATIC ${SOURCE_FILES} ${HEADER_FILES})