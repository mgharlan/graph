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

#include <stack>

template <class T>
class graph{
private:
	static const int MAXSIZE = 100;
	int numberOfEdges = 0;
	int numberOfVertices = 0;
	
	//helper functions:
	bool checkVisited(T value, T* visited, int size);
	void depthHelper(T start, std::stack<T>& s, T* visited, int size);

protected:
	int edgeArray[MAXSIZE][MAXSIZE];
	T vertexArray[MAXSIZE];

public:
	graph();
	graph(const graph<T>& copyGraph);
	~graph();
	bool isEmpty();
	int getNumVertices() const;
	int getNumEdges() const;
	bool checkEdge(T start, T end);
	bool addEdge(T start, T end, int weight);
	bool removeEdge(T start, T end);
	bool addVertex(T value);
	bool removeVertex(T value);
	int getEdgeWeight(T start, T end);
	int getVertexPos(T value);
	T getVertexVal(int pos);
	void depthFirstTraversal(T start);
	void breadthFirstTravel();
	T* getVertexArray();

	//Debugging
	void displayData();
};

#include "graph.cpp"

#endif