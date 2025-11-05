
add_library(lib_vector2 STATIC Vector2.cpp)
target_include_directories(lib_vector2 PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_library(lib_particle STATIC Particle.cpp)
target_include_directories(lib_particle PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_library(lib_obstacle STATIC Obstacle.cpp)
target_include_directories(lib_obstacle PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_library(lib_logger STATIC Logger.cpp)
target_include_directories(lib_logger PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_library(lib_simulation STATIC Simulation.cpp)
target_include_directories(lib_simulation PUBLIC ${PROJECT_SOURCE_DIR}/include)