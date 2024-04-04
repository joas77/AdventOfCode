set(AOC_INCLUDES    ../include)
set(AOC_SOURCES 
    String.cpp
    File.cpp
)

set(AOC_HEADERS
    ${AOC_INCLUDES}/String.hpp
    ${AOC_INCLUDES}/File.hpp
)
add_library(${AOC_LIB}  STATIC
    ${AOC_SOURCES}
    ${AOC_HEADERS}
)

target_include_directories(${AOC_LIB} PUBLIC ${AOC_INCLUDES})
