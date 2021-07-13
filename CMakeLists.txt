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
	-std=c++11
	)
link_directories (
	${CMAKE_CURRENT_SOURCE_DIR}/../../../../usr/lib/
	)
add_executable(  
	out 
    ${SOURCES} #build tất cả các file .o
    ${CMAKE_CURRENT_SOURCE_DIR}/project_test/main/main.cpp #build file *.o của main
	)
target_link_libraries(out sqlite3 pthread) #tiến hành link các file *.o với lib

add_library(add_library_test SHARED ${SOURCES})

message(STATUS  "install lib test ...") 
install(TARGETS add_library_test DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../../../usr/lib)


