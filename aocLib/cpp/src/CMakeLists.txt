set(AOC_INCLUDES    ../include)
set(AOC_SOURCES File.cpp)
add_library(${AOC_LIB}  STATIC
    ${AOC_SOURCES}
)

target_include_directories(${AOC_LIB} PUBLIC ${AOC_INCLUDES})
