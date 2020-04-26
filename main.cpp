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
#include <fstream>
#include <algorithm>

void readFile(graph<std::string> &g);

int main(void)
{

    graph<std::string> g;
    readFile(g);

    int sizeOfVerticesA = g.getNumVertices();
    int indexArray[sizeOfVerticesA];
    int numPaths = 0;

    std::string currentPath, bestPath;
    int currentWeight;
    int bestWeight = 1000000;

    //Create an array of indices based on number of vertices
    for (int i = 0; i < sizeOfVerticesA; i++)
        indexArray[i] = i;
	
	//prep file for writing
	std::ofstream outfile;
	outfile.open("result.txt");

    // O will always be the first element (never shifted) Reno
    //Iterate over all the possible paths
    do
    {
        currentPath = g.getVertexVal(indexArray[0]) + " -> " + g.getVertexVal(indexArray[1]) 
					  + " -> " + g.getVertexVal(indexArray[2]) + " -> " + g.getVertexVal(indexArray[3])
                      + " -> " + g.getVertexVal(indexArray[4]) + " -> " + g.getVertexVal(indexArray[0]) ;
                      //+ " -> " + g.getVertexVal(indexArray[0]);

        currentWeight = g.getEdgeWeight(g.getVertexVal(indexArray[0]), g.getVertexVal(indexArray[1])) +
                        g.getEdgeWeight(g.getVertexVal(indexArray[1]), g.getVertexVal(indexArray[2])) +
                        g.getEdgeWeight(g.getVertexVal(indexArray[2]), g.getVertexVal(indexArray[3])) +
						g.getEdgeWeight(g.getVertexVal(indexArray[3]), g.getVertexVal(indexArray[4])) +
                        g.getEdgeWeight(g.getVertexVal(indexArray[4]), g.getVertexVal(indexArray[0]));

        //compare current to best
		if (currentWeight < bestWeight){
			bestPath = currentPath;
			bestWeight = currentWeight;
		}

        std::cout << currentPath << " : " << currentWeight << std::endl;
		
		//write to file
		outfile<<currentPath<<" : "<<currentWeight << std::endl;

        numPaths++;

    } while (std::next_permutation(indexArray + 1, indexArray + sizeOfVerticesA));

	//write best to file
	outfile<<"Best Path: "<<std::endl;
	outfile<<bestPath<<" : "<<bestWeight<<std::endl;
	
	//close file
	outfile.close();

    std::cout << "numPaths: "<<numPaths << std::endl;
	std::cout<<"Best Path:"<<std::endl;
	std::cout<<bestPath<<" : "<<bestWeight<<std::endl;
	
    //g.displayData();
    return 0;
}

void readFile(graph<std::string> &g)
{
    std::ifstream infile;
    std::string inputfilename = "input.txt";
    std::string Vertex, edgeStart, edgeEnd, newLineChar;
    int edgeWeight;
    bool readEdges = false;

    //Open file
    infile.open(inputfilename);

    while (!infile.eof())
    {
        //Read vertexs until .
        if (!readEdges)
        {
            getline(infile, Vertex);

            //Once . is encountered read edges
            if (Vertex == ".")
                readEdges = true;

            if (!readEdges)
                g.addVertex(Vertex);
        }

        //Read edges
        else
        {
            getline(infile, edgeStart, ',');
            getline(infile, edgeEnd, ',');
            infile >> edgeWeight;
            getline(infile, newLineChar, '\n');
            g.addEdge(edgeStart, edgeEnd, edgeWeight);
        }
    }
}