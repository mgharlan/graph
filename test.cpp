//Andy Alarcon
//Mason Harlan
//CS 302
//Final Project
//4-24-2020
//test.cpp
/*
Changes:
4-25-20: created file
*/

#include <iostream>
#include "graph.h"


int main(void){
	//std::cout<<"Hello World!"<<std::endl;

    // graph<std::string> g;
    // g.addVertex("Reno");
    // g.addVertex("SaltLake");
    // g.addVertex("Dakota");
    // g.addVertex("SanFran");

    // g.addEdge("Reno","SaltLake", 2);
    // g.addEdge("Reno","Dakota", 9);
    // g.addEdge("Reno","SanFran", 3);
    // g.addEdge("Dakota","SaltLake", 8);
    // g.addEdge("SaltLake","SanFran", 1);
	// g.displayData();
	
    // g.removeVertex("Reno");   
    // g.displayData();
	// g.removeVertex("Dakota");
	// g.displayData();
	// g.removeVertex("SanFran");
	// g.displayData();
	// std::cout<<"isEmpty: "<<g.isEmpty()<<std::endl;
	
	// g.addVertex("Reno");
	// g.addVertex("SanFran");
	// g.addVertex("Dakota");
	// g.displayData();
	
	// g.addEdge("Reno","SaltLake", 2);
    // g.addEdge("Reno","Dakota", 9);
    // g.addEdge("Reno","SanFran", 3);
    // g.addEdge("Dakota","SaltLake", 8);
    // g.addEdge("SaltLake","SanFran", 1);
	// g.addEdge("SaltLake", "SanFran", 10);
	// g.displayData();
	// g.removeEdge("Reno","SaltLake");
	// g.displayData();
	
	// std::string* v = g.getVertexArray();
	// graph<std::string> g1(g);
	// g1.displayData();
	
	// graph<std::string> g2;
	// g2.addVertex("1");
	// g2.addVertex("2");
	// g2.addVertex("3");
	// g2.addEdge("1","2",1);
	// g2.addEdge("2","1",1);
	// g2.addEdge("2","3",1);
	// g2.addEdge("3","2",1);
	// g2.displayData();
	// g2.depthFirstTraversal("1");
	// g2.breadthFirstTraversal("1");


	graph<int> g;
	
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(5);
	g.addVertex(6);
	g.addVertex(7);
 	
	g.addEdge(1, 5, 1); 
    g.addEdge(1, 4, 1); 
    g.addEdge(1, 2, 1); 
    
    g.addEdge(2, 7, 1); 
	g.addEdge(2, 6, 1);
	g.addEdge(2, 3, 1);  
     
	g.displayData();
	std::cout << std::endl;
	std::cout<<"DEPTH"<<std::endl;
	g.depthFirstTraversal(1);
	std::cout<<"BREADTH"<<std::endl;
	g.breadthFirstTraversal(1);
}
