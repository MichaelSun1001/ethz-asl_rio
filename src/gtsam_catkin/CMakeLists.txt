cmake_minimum_required(VERSION 3.16.3)
project(gtsam_catkin)

find_package(catkin REQUIRED)
catkin_package(CFG_EXTRAS gtsam-extras.cmake)

include(ExternalProject)

file(MAKE_DIRECTORY ${CATKIN_DEVEL_PREFIX}/include)

ExternalProject_Add(gtsam
        GIT_REPOSITORY git@github.com:rikba/gtsam.git
        GIT_TAG aceac22
        UPDATE_COMMAND ""
        CMAKE_ARGS
            -DCMAKE_INSTALL_PREFIX=${CATKIN_DEVEL_PREFIX}
            -DCMAKE_PREFIX_PATH=${CATKIN_DEVEL_PREFIX}
            -DGTSAM_USE_SYSTEM_EIGEN=ON
            -DGTSAM_WITH_TBB=OFF
            -DCMAKE_BUILD_TYPE:STRING=Release
        BUILD_COMMAND $(MAKE)
        INSTALL_COMMAND $(MAKE) install
        )

add_library(${PROJECT_NAME} src/dependency_tracker.cc)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})
add_dependencies(${PROJECT_NAME} gtsam)

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)