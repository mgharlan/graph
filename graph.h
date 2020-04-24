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

#ifndef GRAPH_H
#define GRAPH_H

template <class T>
class graph{
private:
	const int MAXSIZE = 100;
	int numberOfEdges = 0;
	int numberOfVertices = 0;
	int edgeArray[MAXSIZE][MAXSIZE];
	T vertexArray[MAXSIZE];

public:
	graph();
	graph(graph<T>& copyGraph);
	~graph();
	bool isEmpty();
	int getNumVertices();
	int getNumEdges();
	bool checkEdge(T start, T end);
	bool addEdge(T start, T end, int weight);
	bool removeEdge(T start, T end);
	bool addVertex(T value);
	bool removeVertex(T value);
	int getEdgeWeight(T start, T end);
	int getVertexPos(T value);
	T getVertexVal(int pos);
	void depthFirstTraversal();
	void breadthFirstTravel();
};

#include "graph.cpp"

#endif