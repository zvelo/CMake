
project(add_definitions_command)

add_definitions(-DCMAKE_IS_FUN -DCMAKE_IS=Fun -DCMAKE_IS_="Fun" -DCMAKE_IS_REALLY="Very Fun")
add_definitions(-DCMAKE_IS_="Fun" -DCMAKE_IS_REALLY="Very Fun" -DCMAKE_IS_FUN -DCMAKE_IS=Fun)
add_definitions(-DBUILD_IS_DEBUG=$<CONFIG:Debug> -DBUILD_IS_NOT_DEBUG=$<NOT:$<CONFIG:Debug>>)

add_executable(add_definitions_command_executable ../compiletest.cpp)
