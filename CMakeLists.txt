cmake_minimum_required(VERSION 3.31)
project(Project_2_Revised_Ornelas)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project_2_Revised_Ornelas main.cpp
        InvestmentAccount.cpp
        InvestmentAccount.h
        PrintDetails.cpp
        PrintDetails.h
        InputValidation.cpp
        InputValidation.h)
