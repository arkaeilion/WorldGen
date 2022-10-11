project(Sustain VERSION 0.1.0)

file(GLOB SUSTAIN_CORE_SRC "src/core/*.h" "src/core/*.cpp")
add_library(${PROJECT_NAME} ${SUSTAIN_CORE_SRC})

find_package(Vulkan REQUIRED)
find_package(sdl2 REQUIRED)
find_package(glm REQUIRED)
find_package(spdlog REQUIRED)
find_package(imgui REQUIRED)
find_path(STB_INCLUDE_DIRS "stb_image.h")
find_library(INIH_LIBRARY inih)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		"${CMAKE_CURRENT_SOURCE_DIR}/src/"
		${Vulkan_INCLUDE_DIRS}
        ${SDL2_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
        ${SPDLOG_INCLUDE_DIRS}
        ${IMGUI_INCLUDE_DIRS}
        ${STB_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
		Vulkan::Vulkan
		SDL2::SDL2
		SDL2::SDL2main
		glm::glm
		spdlog::spdlog
		imgui::imgui
		${INIH_LIBRARY}
)
