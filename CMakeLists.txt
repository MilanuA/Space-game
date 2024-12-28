cmake_minimum_required(VERSION 3.30)
project(SampleGame)

set(CMAKE_CXX_STANDARD 20)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_MakeAvailable(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    endif()
endif()

# Our Project
add_executable(${PROJECT_NAME} main.cpp
        src/ui/button/Button.cpp
        src/ui/button/Button.h
        src/scenes/SceneManager.cpp
        src/scenes/SceneManager.h
        src/scenes/Scene.cpp
        src/scenes/Scene.h
        src/scenes/MainMenu.cpp
        src/scenes/MainMenu.h
        src/scenes/Gameplay.cpp
        src/scenes/Gameplay.h
)
find_path(RAYLIB_INCLUDE_DIR raylib.h
        PATHS ${CMAKE_BINARY_DIR}/_deps/raylib-build/raylib/include
        REQUIRED
)

target_include_directories(${PROJECT_NAME} PRIVATE ${RAYLIB_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html") # Tell Emscripten to build an example.html file.
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
