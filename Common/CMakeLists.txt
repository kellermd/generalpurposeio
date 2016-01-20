message("Common CMakeLists.txt begin")

FILE(GLOB_RECURSE sourceVar ./ *.cpp *.c *.h)

add_library(Common ${sourceVar})
#target_link_libraries(server js)

message("Common CMakeLists.txt end")