cmake_minimum_required(VERSION 2.8)

project(cs791a)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "~/ClionProjects/opengl_engine/bin")


include_directories("include")
include_directories("include/objects")
include_directories("include/programs")



aux_source_directory(src Engine_src)
aux_source_directory("src/objects" objects_src)
aux_source_directory("src/programs" programs_src)



set(Engine_src ${Engine_src} ${objects_src} ${programs_src})
#add_library(GameEngine ${GameEngine_src})
add_executable(cs791a ${Engine_src})

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") #apple
    message(STATUS "Mac OS Detected")
    include_directories("/usr/local/include/SDL2")
    include_directories("/usr/local/include/freetype2")
    include_directories("/usr/local/include/gdal")
    set(LIBRARIES_TO_LINK "SDL2" "boost_program_options" "freeimageplus" "assimp" "gdal")
    set(MAC_FRAMEWORKS "-framework OpenGL")
    set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11 -stdlib=libc++ -O2")

    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework OpenGL -framework Cocoa")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message(STATUS "Linux OS Detected")
    set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
    include(FindPkgConfig)
    pkg_search_module(SDL2 REQUIRED sdl2)
    pkg_search_module(GLEW REQUIRED glew)
    pkg_search_module(ASSIMP REQUIRED assimp)
    #pkg_search_module(GDAL REQUIRED gdal)
    #find_package(Boost REQUIRED COMPONENTS program_options python)
    find_package(Boost REQUIRED COMPONENTS program_options)
    #pkg_search_module(PYTHON REQUIRED python2)
    include_directories(${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} ${ASSIMP_INCLUDE_DIRS})
    include_directories("/usr/include/gdal")
    set(LIBRARIES_TO_LINK ${SDL2_LIBRARIES} ${GLEW_LIBRARIES} ${Boost_LIBRARIES} ${ASSIMP_LIBRARIES} "freeimageplus")
    set(LIBRARIES_TO_LINK ${LIBRARIES_TO_LINK} "gdal")

else()
    message(STATUS "Windows OS Detected")
    message(FATAL_ERROR0 "Windows is not supported")

endif()

target_link_libraries(cs791a ${LIBRARIES_TO_LINK})