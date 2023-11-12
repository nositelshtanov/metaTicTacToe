cmake_minimum_required(VERSION 3.26)
project(ttt)

set(CMAKE_CXX_STANDARD 14)

add_executable(ttt
        main.cpp
        ttt_meta_session.cpp
        ttt_meta_session.h
        ttt_engine.cpp
        ttt_engine.h
        ttt_meta.cpp
        ttt_meta.h
        ttt_simple.cpp
        ttt_simple.h
        ttt_simple_session.cpp
        ttt_simple_session.h)
