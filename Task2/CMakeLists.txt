cmake_minimum_required(VERSION 3.6)
set(NAME Task2)
project(${NAME})

# set (CMAKE_PREFIX_PATH /GEANT4/) #Here should be the G4 install dir
# set(CMAKE_PREFIX_PATH /home/student/geant4/geant4-install/) #Uncomment this on CLion

option(WITH_GEANT4_UIVIS "Build project with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
    find_package(Geant4 REQUIRED ui_all vis_all)
else()
    find_package(Geant4 REQUIRED)
endif() 

include(${Geant4_USE_FILE}) 
include_directories(${PROJECT_SOURCE_DIR}/include)


file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh) 
 
add_executable(${NAME} Task2.cc ${sources} ${headers})
target_link_libraries(${NAME} ${Geant4_LIBRARIES})

