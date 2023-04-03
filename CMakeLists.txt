cmake_minimum_required(VERSION 3.24)
project(DAproject)

set(CMAKE_CXX_STANDARD 17)

add_executable(DAproject main.cpp Graph.cpp Graph.h VertexEdge.cpp VertexEdge.h Station.cpp Station.h CPheadquarters.cpp CPheadquarters.h)
