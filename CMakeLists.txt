cmake_minimum_required(VERSION 2.8)
add_definitions(
    -std=c++11
)
add_executable(main
    main.cpp
    resource/vector.hpp
    resource/list.hpp
)
