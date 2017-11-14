#ifndef GRAPH_H
#define GRAPH_H

#include<cstdio>
#include"../LinkedList/LinkedList.h"

class GraphNode {
	public: struct GraphNodeEdge {
	public:
		float length;
		GraphNode *neighbor;
		GraphNodeEdge(GraphNode *nd, float lgth);
		bool operator==(const GraphNodeEdge& nd);
		bool operator!=(const GraphNodeEdge& nd);
	};
public:
	int nodeID;
	LinkedList<GraphNodeEdge> links;
	void Link(GraphNode *nd, float length);
	void Unlink(GraphNode *nd);
	GraphNode(int id);
	bool operator==(const GraphNode& nd);
	bool operator!=(const GraphNode& nd);
	void PrintAll();
};

template class LinkedList<GraphNode*>;
template class LinkedList<GraphNode::GraphNodeEdge>;

class Graph {
	LinkedList<GraphNode*> nodes;

public:
	Graph();
	~Graph();
	void AddNode(int nd);
	void AddNode(GraphNode *nd);

	void RemoveNode(int nd, bool dealloc);
	void RemoveNode(GraphNode *nd, bool dealloc);

	void LinkNodes(int nd1, int nd2, float length);
	void LinkNodes(GraphNode *nd1, GraphNode *nd2, float length);

	void UnlinkNodes(int nd1, int nd2);
	void UnlinkNodes(GraphNode *nd1, GraphNode *nd2);

	GraphNode *GetPointerByID(int ndID);
	void PrintAllNodes();

};

#endif
