add_library(binary_numbers STATIC binary_numbers.cpp)
add_library(cypher STATIC cypher.cpp)
add_library(app STATIC app.cpp)

target_include_directories(binary_numbers PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(cypher PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(app PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(app
                        binary_numbers
                        cypher)


add_executable(Lab3 main.cpp)
target_link_libraries(Lab3 PRIVATE app)