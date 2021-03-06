# Antomic Engine Launcher
FILE(GLOB_RECURSE LAUNCHER_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
FILE(GLOB_RECURSE LAUNCHER_HDR "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
add_executable("${PROJECT_NAME}Launcher" ${LAUNCHER_HDR} ${LAUNCHER_SRC})
target_compile_features("${PROJECT_NAME}Launcher" PUBLIC cxx_std_17)

# Antomic Engine
target_include_directories( 
    "${PROJECT_NAME}Launcher"
    PRIVATE
    "${PROJECT_SOURCE_DIR}/engine"
)

target_link_libraries(
    "${PROJECT_NAME}Launcher" 
    PRIVATE
    "${PROJECT_NAME}Engine"
)

# OpenGL RenderAPI Support
# https://www.opengl.org/
if(OPENGL_SUPPORT)
    target_link_libraries(
        "${PROJECT_NAME}Launcher"
        PRIVATE
        OpenGL::OpenGL
    )
endif() 

# GLM Library setup
# https://github.com/g-truc/glm
target_include_directories( 
    "${PROJECT_NAME}Launcher"
    PRIVATE
    "${GLM_DIR}"
)

# single-file public domain (or MIT licensed) libraries for C/C++
# https://github.com/nothings/stb
target_link_libraries(
    "${PROJECT_NAME}Launcher" 
    PRIVATE
    "stb"
)

# Logging Library setup
# https://github.com/gabime/spdlog.git
target_link_libraries( 
    "${PROJECT_NAME}Launcher"
    PRIVATE
    spdlog::spdlog
)

# Logging Library setup
# https://github.com/gabime/spdlog.git
target_link_libraries( 
    "${PROJECT_NAME}Launcher"
    PRIVATE
    nlohmann_json::nlohmann_json
)
