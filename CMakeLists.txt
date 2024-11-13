# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("Homework_11")

set(INCLUDE
	"inc/main.h"
	"inc/containers.h"
	"inc/functions.h"
	"inc/pimpl.h"
)

set(SRC
	"src/main.cpp"
	"src/containers.cpp"
	"src/functions.cpp"
	"src/pimpl.cpp"
)

add_executable (Homework_11
	${INCLUDE} 
	${SRC}
)

target_include_directories(Homework_11
        PUBLIC
        ./inc
        ./src
)