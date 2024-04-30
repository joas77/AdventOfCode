set(AOC_INCLUDES    ../include)

# CMake does not recommend using find(GLOBAL ...) https://cmake.org/cmake/help/latest/command/file.html#filesystem
# So all files will be need to add manually here
set(AOC_SOURCES 
    File.cpp
    Geometry.cpp
    Regex.cpp
    String.cpp
    Utils.cpp
)

set(AOC_HEADERS
    ${AOC_INCLUDES}/File.hpp
    ${AOC_INCLUDES}/Geometry.hpp
    ${AOC_INCLUDES}/Regex.hpp
    ${AOC_INCLUDES}/String.hpp
    ${AOC_INCLUDES}/Utils.hpp
)
add_library(${AOC_LIB}  STATIC
    ${AOC_SOURCES}
    ${AOC_HEADERS}
)

target_include_directories(${AOC_LIB} PUBLIC ${AOC_INCLUDES})
