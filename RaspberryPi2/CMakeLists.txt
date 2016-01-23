message("RaspberryPi2 CMakeLists.txt begin")

FILE(GLOB_RECURSE sourceVar ./ *.cpp *.c *.h)
message(${sourceVar})

add_library(RaspberryPi2 ${sourceVar})
target_link_libraries(RaspberryPi2 Common)

message("RaspberryPi2 CMakeLists.txt end")