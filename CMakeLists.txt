cmake_minimum_required(VERSION 2.6)
project(generalpurposeio)
message("Root CMakeLists.txt begin")

add_subdirectory (Common) 
add_subdirectory (RaspberryPi2)
add_subdirectory (Program)

# -----------------------------------------------------------------------------
# add the executable
add_executable(generalpurposeio Program/main.cpp)
target_link_libraries (generalpurposeio Common RaspberryPi2)
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# install
install(TARGETS generalpurposeio RUNTIME DESTINATION bin)
# -----------------------------------------------------------------------------

message("Root CMakeLists.txt end")
