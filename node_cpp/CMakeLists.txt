cmake_minimum_required (VERSION 3.2)
project(test)


#set(EXECUTABLE_OUTPUT_PATH  ./output/)
add_compile_options(-g -Wall)

aux_source_directory(src/ SRC)

add_executable(allen ${SRC})


