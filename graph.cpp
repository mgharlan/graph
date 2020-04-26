//Andy Alarcon
//Mason Harlan
//CS 302
//Final Project
//4-24-2020
//main.cpp
/*
Changes:
4-24-20: created file
4-25-20: added functions
*/
#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "graph.h"
#include <iostream>

template<class T>
graph<T>::graph(){
	for(int i =0;i<MAXSIZE;i++){
		for(int j=0;j<MAXSIZE;j++){
			edgeArray[i][j] = 0;
		}
	}
}

template<class T>
graph<T>::graph(const graph<T>& copyGraph){
	numberOfEdges = copyGraph.getNumEdges();
	numberOfVertices = copyGraph.getNumVertices();
	for(int i =0;i< numberOfEdges;i++){
		for(int j=0;j<numberOfEdges;j++){
			edgeArray[i][j] = copyGraph.edgeArray[i][j];
		}
	}
	for(int i =0;i<numberOfVertices;i++){
		vertexArray[i] = copyGraph.vertexArray[i];
	}
}

template<class T>
graph<T>::~graph(){}

template<class T>
bool graph<T>::isEmpty(){
	return numberOfVertices == 0; //is it this one?
	//return numberOfEdges == 0; //or this one?
}

template<class T>
int graph<T>::getNumVertices() const{
	return numberOfVertices;
}

template<class T>
int graph<T>::getNumEdges() const{
	return numberOfEdges;
}

template<class T>
bool graph<T>::checkEdge(T start, T end){
	
	if(!isEmpty())
	{
		int startIndex = getVertexPos(start);
		int endIndex = getVertexPos(end);

		//Value is > -1 so the vertices are in the array
		if(startIndex >= 0 && endIndex >= 0 && edgeArray[startIndex][endIndex] > 0)
			return true;		
	}

	return false;
}

template<class T>
bool graph<T>::addEdge(T start, T end, int weight){
	
	if(!isEmpty())
	{
		int startIndex = getVertexPos(start);
		int endIndex = getVertexPos(end);

		//Value is > -1 so the vertices are in the array
		if(startIndex >= 0 && endIndex >= 0)
		{
			edgeArray[startIndex][endIndex] = weight;
			edgeArray[endIndex][startIndex] = weight;
			numberOfEdges++;
			return true;
		}
	}

	return false;
	
}

template<class T>
bool graph<T>::removeEdge(T start, T end){

	//Avoid removing same vertices
	if(start == end)
	 return false;

	else if(!isEmpty())
	{
		int startIndex = getVertexPos(start);
		int endIndex = getVertexPos(end);

		//Value is > -1 so the vertices are in the array
		if(startIndex >= 0 && endIndex >= 0 && edgeArray[startIndex][endIndex] != 0)
		{
			edgeArray[startIndex][endIndex] = 0;
			edgeArray[endIndex][startIndex] = 0;
			numberOfEdges--;
			return true;
		}

	}

	return false;
}

template<class T>
bool graph<T>::addVertex(T value){
	if (numberOfVertices < MAXSIZE){
		vertexArray[numberOfVertices] = value;
		numberOfVertices++;
		return true;
	}
	else{
		return false;
	}
}

template<class T>
bool graph<T>::removeVertex(T value)
{
	int removeIndex = getVertexPos(value);

	if(!isEmpty() && removeIndex >= 0)
	{
		// //Remove all edges from the given vertex
		for (int i = 0; i < numberOfVertices; i++)
			removeEdge(value, vertexArray[i]);
		

		//Shift the column elements left
		for (int i = 0; i < numberOfVertices; i++)
		{
			for (int j = removeIndex; j < numberOfVertices; j++)
			{
				edgeArray[i][j] = edgeArray[i] [j+1];
			}	
		}

		//Shift the row elements up
		for (int i = removeIndex; i < numberOfVertices; i++)
		{
			for (int j = 0; j < numberOfVertices; j++)
			{
				edgeArray[i][j] = edgeArray[i +1] [j];
			}	
		}
		
		//Remove vertex from the vertex array
		for (int i = removeIndex; i < numberOfVertices; i++)
		{
			vertexArray[i] = vertexArray[i+1];
		}

		numberOfVertices--;
		return true;
	}

	return false;
}

template<class T>
int graph<T>::getEdgeWeight(T start, T end){
	if(!isEmpty())
	{
		int startIndex = getVertexPos(start);
		int endIndex = getVertexPos(end);

		//Value is > -1 so the vertices are in the array
		if(startIndex >= 0 && endIndex >= 0)
			return edgeArray[startIndex][endIndex];
	}

	return -1;
}

template<class T>
int graph<T>::getVertexPos(T value){	
	if(!isEmpty())
	{
		//Search vertex array to get position
		for (int i = 0; i < numberOfVertices ; i++)
		{
			if(vertexArray[i] == value)
			return i;
		}
	}

	return -1;
}

template<class T>
T graph<T>::getVertexVal(int pos){
	if(!isEmpty() && pos < numberOfVertices)
		return vertexArray[pos];
	
	throw(10);//return false;
}

template<class T>
void graph<T>::depthFirstTraversal(T start){
	if(isEmpty() or getVertexPos(start) == -1){
		throw(10);
	}
	std::stack<T> s;
	T visited[numberOfVertices];
	visited[0] = start;
	int vSize = 1;
	
	s.push(start);
	depthHelper(start, s, visited, vSize);
}

template<class T>
void graph<T>::depthHelper(T start, std::stack<T>& s, T* visited, int size){
	for (int i =0;i<numberOfVertices;i++){
		T val = getVertexVal(i);
		if(checkEdge(start,val) != 0 and 
			not checkVisited(val,visited,size)){
				s.push(val);
				visited[size] = val;
				size++;
				depthHelper(val,s,visited,size);
		}
	}
	std::cout<<s.top()<<std::endl;
	s.pop();
}

template<class T>
bool graph<T>::checkVisited(T value, T* visited, int size){
	for (int i =0;i<size;i++){
		if(value == visited[i]){
			return true;
		}
	}
	return false;
}

template<class T>
void graph<T>::breadthFirstTraversal(T start){
	if(isEmpty() or getVertexPos(start) == -1){
		throw(10);
	}
	std::queue<T> q;
	T visited[numberOfVertices];
	visited[0] = start;
	int vSize = 1;
	
	q.push(start);
	breadthHelper(start, q, visited, vSize);
}

template<class T>
void graph<T>::breadthHelper(T start, std::queue<T>& q, T* visited, int size){
	for (int i =0;i<numberOfVertices;i++){
		T val = getVertexVal(i);
		if(checkEdge(start,val) != 0 and 
			not checkVisited(val,visited,size)){
				q.push(val);
				visited[size] = val;
				size++;
				breadthHelper(val,q,visited,size);
		}
	}
	std::cout<<q.front()<<std::endl;
	q.pop();
}

template<class T>
void graph<T>::displayData(){
	std::cout << std::endl;
	std::cout << "Number of Edges : " << numberOfEdges << std::endl;
	std::cout << "Number of Vertices : " << numberOfVertices << std::endl;

	std::cout << std::endl;
	std::cout << "Vertex Array : " << std::endl;

	for (int i = 0; i < numberOfVertices; i++)
	{
		std::cout << vertexArray[i] << " | ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Edge Array : " << std::endl;

	for (int i = 0; i < numberOfVertices; i++)
	{
		for (int j = 0; j < numberOfVertices; j++)
		{
			std::cout << edgeArray[i][j] << " | " ;
		}

		std::cout << std::endl;
		
	}
}	

template<class T>
T* graph<T>::getVertexArray(){
	return vertexArray;
}

#endif