project(WorldGen VERSION 0.1.0)

file(GLOB WORLD_GEN_SRC "src/*.h" "src/*.cpp")
add_executable(${PROJECT_NAME} ${WORLD_GEN_SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE Sustain)
