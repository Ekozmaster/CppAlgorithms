#include<cstdio>
#include<iostream>
#include<cstdlib>
#include "Graph/Graph.h"

int main(){
	//TestMoodleExample(false);
	Graph graph = Graph();
	graph.AddNode(1);
	graph.AddNode(1);
	graph.AddNode(2);
	graph.AddNode(3);
	graph.AddNode(4);

	graph.LinkNodes(1, 2, 1);
	graph.LinkNodes(graph.GetPointerByID(1), new GraphNode(7), 2);
	graph.PrintAllNodes();
	return 0;
}
