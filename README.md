# SAT-Solver-for-Vertex-Cover-Problem

The project is to help the local police department of Waterloo with their installation of security cameras at traffic intersections. This is implemented by solving a particular kind of optimization problem, called the Vertex Cover problem, in this context. The idea is for the police to be able to minimize the number of cameras they need to install, and still be as effective as possible with their monitoring.

The basic functionalities implemented in the below files are explained below:

Graph.h - This is the header file for the corresponding cpp file Graph.cpp
Graph.cpp - This c++ file is responsible for generating the graph by constructing nodes and edges

VertexCoverAlgo.h - This is the header file for corresponding cpp file VertexCoverAlgo.cpp
VertexCoverAlgo.cpp - Three differenet approximation algorithms(CNF-SAT, APPROX_VC_1 and APPROX_VC_2) are written in this file for finding the Vertex Cover of a given graph

prj-ece650.cpp - This is the main C++ file. It divides the program into different threads and runs the three different algorithms for finding the vertex cover.

