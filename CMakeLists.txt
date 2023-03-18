cmake_minimum_required(VERSION 3.0)

project(Run_SPJ)

add_executable(Solution solution/main.cpp)
add_executable(SPJ src/spj.cpp)

# add_executable(Run_SPJ src/blank_target.cpp)
# add_dependencies(Run_SPJ run_spj)

add_custom_target(
        Run_Solution
        DEPENDS Solution
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_BINARY_DIR}/1.in
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/solution/1.in ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Solution < ${CMAKE_CURRENT_BINARY_DIR}/1.in > ${CMAKE_CURRENT_BINARY_DIR}/1.out
        COMMENT "Copy 1.in & Run Solution -> 1.out"
)

add_custom_target(
        Run_SPJ
        DEPENDS Run_Solution SPJ 
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/SPJ 1.in 1.out > ${CMAKE_CURRENT_BINARY_DIR}/spj.log || (exit 0)
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_SOURCE_DIR}/solution/spj.log || (exit 0)
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/spj.log ${CMAKE_CURRENT_SOURCE_DIR}/solution/spj.log || (exit 0)
        COMMENT "Run SPJ & Copy spj.log -> solution/spj.log"
)
