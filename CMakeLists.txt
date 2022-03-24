if(NOT DEFINED CMAKE_MINIMUM_REQUIRED_VERSION)
    cmake_minimum_required(VERSION 3.16)
endif()

project(ScytheCase)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/inc)

set(PROJECT_SOURCES
            ${PROJECT_SOURCE_DIR}/main.cpp
						${PROJECT_SOURCE_DIR}/PathListModel.cpp
						${PROJECT_SOURCE_DIR}/EventTableModel.cpp
            )
set(PROJECT_HEADERS
	          ${PROJECT_INCLUDE_DIR}/PathListModel.h
						${PROJECT_INCLUDE_DIR}/EventTableModel.h
            )

include_directories(${PROJECT_INCLUDE_DIR})

find_package(Qt6 REQUIRED COMPONENTS Quick Qml QuickWidgets QuickControls2) #QuickDialogs2

qt_add_resources(RSCS qml/qml.qrc icon/icon.qrc)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${RSCS})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Quick Qt6::Qml Qt6::QuickWidgets Qt6::QuickControls2)#Qt6::QuickDialogs2
