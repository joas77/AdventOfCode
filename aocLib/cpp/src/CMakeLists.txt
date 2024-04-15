set(AOC_INCLUDES    ../include)

# TODO improve script by automatically add all hpp and cpp files
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
