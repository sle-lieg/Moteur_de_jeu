cmake_minimum_required(VERSION 2.8)
project(moteur_de_jeu)

add_compile_options(-std=c++11 -Wall -Wextra -Werror)

include_directories(headers classes templates)

set(SOURCE_FILES
	classes/Vector_base.cpp
	classes/Vector2.cpp
	classes/Vector3.cpp
	classes/Vector4.cpp
)

set(TEST_FILES
	tests/Vector2_test.cpp
)

find_package(Boost 1.69 REQUIRED COMPONENTS unit_test_framework)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_compile_options(${PROJECT_NAME} PUBLIC -fPIC)
target_include_directories(${PROJECT_NAME} PUBLIC)

# add_executable(${PROJECT_NAME}_test main.cpp)
# target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})

################################################################################
##################################### TESTS ####################################
################################################################################

enable_testing()
add_executable(test_vector2 ${TEST_FILES})

target_include_directories(test_vector2 PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(test_vector2 ${PROJECT_NAME} ${Boost_LIBRARIES})
add_test(Vector2 test_vector2)

################################################################################
#################################### INSTALL ###################################
################################################################################

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_test
	DESTINATION bin
	RENAME mdj	
)

