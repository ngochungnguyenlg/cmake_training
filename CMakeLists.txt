#build bình thường
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Release) #set chế độ build

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}/project_test/commonlib/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/project_test/commonlib/source/
    ${CMAKE_CURRENT_SOURCE_DIR}/project_test/toturial_project/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/project_test/toturial_project/source/
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../usr/include/
    )
#file(
#	GLOB SOURCES "project_test/commonlib/source/*.cpp"
#	GLOB SOURCES "project_test/toturial_project/source/*.cpp"
#	)
#làm thủ công add các source .cpp
#set(SOURCES 
#	${CMAKE_CURRENT_SOURCE_DIR}/project_test/commonlib/source/mystring.cpp
#	${CMAKE_CURRENT_SOURCE_DIR}/project_test/toturial_project/source/customer.cpp
#	${CMAKE_CURRENT_SOURCE_DIR}/project_test/toturial_project/source/sale.cpp
#	${CMAKE_CURRENT_SOURCE_DIR}/project_test/toturial_project/source/saler.cpp
#	${CMAKE_CURRENT_SOURCE_DIR}/project_test/toturial_project/source/sqlhandle.cpp
#	${CMAKE_CURRENT_SOURCE_DIR}/project_test/toturial_project/source/person.cpp
#	)

#tự động tìm kiếm các source .cpp bằng lệnh GLOB hoặc GLOB_RECURSE
file (GLOB SOURCES 
	project_test/commonlib/source/*.cpp
	project_test/toturial_project/source/*.cpp
	)
add_definitions(
	-D_LINUX_
)
add_compile_options(
	-g
	-w
	-std=c++11
	)
link_directories (
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../usr/lib/
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../usr/include/
	# ${CMAKE_CURRENT_SOURCE_DIR}/build/
	)
#==============================================================================
#set example
#https://hsf-training.github.io/hsf-training-cmake-webpage/05-variables/index.html
#https://cmake.org/cmake/help/v3.0/command/set.html
set(MY_VAR "hello world")
message(STATUS ${MY_VAR})
set(MY_VAR "hello world _______")
message(STATUS ${MY_VAR})
set(MY_VAR "hello world" CACHE STRING "Description")
message(STATUS ${MY_VAR})

#==============================================================================
# build with static lib
# set(PROJECT_LINK_LIBS libbuild_static_test.a)
# add_executable(  
# 	out 
#     # ${SOURCES} #build tất cả các file .o
#     ${CMAKE_CURRENT_SOURCE_DIR}/project_test/main/main.cpp #build file *.o của main
# 	)
# target_link_libraries(out 
# 	pthread 
# 	${PROJECT_LINK_LIBS}
# 	sqlite3
# 	) #tiến hành link các file *.o với lib
#===============================================================================
#buil with share lib
# set(PROJECT_LINK_LIBS build_share_test.so)
# add_executable(  
# 	out 
#     # ${SOURCES} #build tất cả các file .o
#     ${CMAKE_CURRENT_SOURCE_DIR}/project_test/main/main.cpp #build file *.o của main
# 	)
# target_link_libraries(out 
# 	pthread 
# 	${PROJECT_LINK_LIBS}
# 	sqlite3
# 	) #tiến hành link các file *.o với lib
#===============================================================================
#build lib and install lib
add_executable(  
	out 
    ${SOURCES} #build tất cả các file .o
    ${CMAKE_CURRENT_SOURCE_DIR}/project_test/main/main.cpp #build file *.o của main
	)
target_link_libraries(out 
	pthread 
	sqlite3
	) #tiến hành link các file *.o với lib
add_library(build_share_test SHARED ${SOURCES})
add_library(build_static_test STATIC ${SOURCES})

install(TARGETS build_share_test DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../../../usr/lib)
install(TARGETS build_static_test DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../../../usr/lib)


