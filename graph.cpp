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
#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "graph.h"
#include <iostream>

template<class T>
graph<T>::graph(){}

template<class T>
graph<T>::graph(const graph<T>& copyGraph){
	
}

template<class T>
graph<T>::~graph(){}

template<class T>
bool graph<T>::isEmpty(){
	return numberOfEdges == 0;
}

template<class T>
int graph<T>::getNumVertices(){
	return numberOfVertices;
}

template<class T>
int graph<T>::getNumEdges(){
	return numberOfEdges;
}

template<class T>
bool graph<T>::checkEdge(T start, T end){
	if(isEmpty()){
		return false;
	}
	//else if(){}
	return false;
}

template<class T>
bool graph<T>::addEdge(T start, T end, int weight){
	
}

template<class T>
bool graph<T>::removeEdge(T start, T end){
	
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
bool graph<T>::removeVertex(T value){
	
}

template<class T>
int graph<T>::getEdgeWeight(T start, T end){
	
}

template<class T>
int graph<T>::getVertexPos(T value){
	
}

template<class T>
T graph<T>::getVertexVal(int pos){
	
}

template<class T>
void graph<T>::depthFirstTraversal(){
	
}

template<class T>
void graph<T>::breadthFirstTravel(){
	
}

#endif