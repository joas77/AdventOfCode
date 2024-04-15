set(AOC_INCLUDES    ../include)

# CMake does not recommend using find(GLOBAL ...) https://cmake.org/cmake/help/latest/command/file.html#filesystem
# So all files will be need to add manually here
set(AOC_SOURCES 
    String.cpp
    File.cpp
    Utils.cpp
    Regex.cpp
)

set(AOC_HEADERS
    ${AOC_INCLUDES}/String.hpp
    ${AOC_INCLUDES}/File.hpp
    ${AOC_INCLUDES}/Utils.hpp
    ${AOC_INCLUDES}/Regex.hpp
)
add_library(${AOC_LIB}  STATIC
    ${AOC_SOURCES}
    ${AOC_HEADERS}
)

target_include_directories(${AOC_LIB} PUBLIC ${AOC_INCLUDES})
