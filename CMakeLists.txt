include(FetchContent)
cmake_minimum_required(VERSION 3.20.0)

#set(CMAKE_TOOLCHAIN_FILE "G:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(OpenGL-Boilerplate)

add_executable(${PROJECT_NAME} src/main.cpp src/glad.c)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.3.8
)

FetchContent_MakeAvailable(glfw)

set(CMAKE_PREFIX_PATH "G:/dev/vcpkg/installed/x64-windows/share")
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad glm::glm glfw)
