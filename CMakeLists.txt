cmake_minimum_required(VERSION 4.1)
project(HospitalOS)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HospitalOS
        Doctor.cpp
        Doctor.h
        Room.cpp
        Room.h
        main.cpp
        Patient.cpp
        Patient.h
        Hospital.h
        Hospital.cpp
        UI.h
        UI.cpp)
