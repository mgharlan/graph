//Andy Alarcon
//Mason Harlan
//CS 302
//Final Project
//4-24-2020
//main.cpp
/*
Changes:
4-24-20: created file
*/

#include <iostream>
#include "graph.h"


int main(void)
{
    //std::cout<<"Hello World!"<<std::endl;

    graph<std::string> g;
    g.addVertex("Reno");
    g.addVertex("SaltLake");
    g.addVertex("Dakota");
    g.addVertex("SanFran");

    g.addEdge("Reno","SaltLake", 2);
    g.addEdge("Reno","Dakota", 9);
    g.addEdge("Reno","SanFran", 3);
    g.addEdge("Dakota","SaltLake", 8);
    g.addEdge("SaltLake","SanFran", 1);

    //g.removeVertex("Reno");
    
    g.displayData();
}