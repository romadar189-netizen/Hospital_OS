
cmake_minimum_required(VERSION 3.16)
project(HospitalOS)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(libpqxx CONFIG REQUIRED)

add_executable(HospitalOS
        Source/main.cpp
        Source/Doctor.cpp
        Source/Room.cpp
        Source/Patient.cpp
        Source/Hospital.cpp
        Source/UI.cpp
        Source/Database.cpp
)

target_include_directories(HospitalOS PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Header
)

target_link_libraries(HospitalOS PRIVATE pqxx)
