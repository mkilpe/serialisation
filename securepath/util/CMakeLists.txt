file(GLOB SRC *.cpp *.hpp)
add_library(util STATIC ${SRC})

add_subdirectory(test)