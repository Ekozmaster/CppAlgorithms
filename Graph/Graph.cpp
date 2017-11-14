#include"Graph.h"
#include<cstdlib>
#include<iostream>

// EDGE
GraphNode::GraphNodeEdge::GraphNodeEdge(GraphNode *nd, float lgth){
	length = lgth;
	neighbor = nd;
};

bool GraphNode::GraphNodeEdge::operator==(const GraphNodeEdge& nd){
	return (*(nd.neighbor) == *neighbor);
}

bool GraphNode::GraphNodeEdge::operator!=(const GraphNodeEdge& nd){
	return (*(nd.neighbor) != *neighbor);
}



// GRAPH NODE
GraphNode::GraphNode(int id){
	nodeID = id;
	links = LinkedList<GraphNodeEdge>();
}

bool GraphNode::operator==(const GraphNode& nd){
	return (nd.nodeID == nodeID);
}

bool GraphNode::operator!=(const GraphNode& nd){
	return (nd.nodeID != nodeID);
}

void GraphNode::Link(GraphNode *nd, float length){
	GraphNodeEdge edge = GraphNodeEdge(nd, length);
	if(!links.Contains(edge)){
		links.AddAtTail(edge);
	}
}

void GraphNode::Unlink(GraphNode *nd){
	LinkedList_Node<GraphNodeEdge> *temp = links.head;
	bool found = false;
	int pos = 0;
	while(temp && !found){
		if(temp->data.neighbor == nd){
			links.RemoveFromPos(pos);
			found = true;
		} else {
			temp = temp->next;
			pos++;
		}
	}
}

void GraphNode::PrintAll(){
	LinkedList_Node<GraphNodeEdge> *temp = links.head;
	printf("[%d]", nodeID);
	while(temp){
		printf("--%.1f--[%d]", temp->data.length, temp->data.neighbor->nodeID);
		temp = temp->next;
	}
	printf("\n");
}



// GRAPH
Graph::Graph(){
	nodes = LinkedList<GraphNode*>();
}

Graph::~Graph(){
	LinkedList_Node<GraphNode*> *temp = nodes.head;
	while(temp){
		delete(temp->data);
		temp = temp->next;
	}
}

void Graph::AddNode(int nd){
	GraphNode *node = GetPointerByID(nd);
	if(!node){
		node = new GraphNode(nd);
		nodes.AddAtTail(node);
	}
}

void Graph::AddNode(GraphNode *nd){
	GraphNode *node = GetPointerByID(nd->nodeID);
	if(!node){
		if(!nodes.Contains(nd)){
			nodes.AddAtTail(nd);
		}
	}
}

void Graph::RemoveNode(int nd, bool dealloc){
	GraphNode *node = GetPointerByID(nd);
	if(node != NULL){
		LinkedList_Node<GraphNode*> *temp = nodes.head;
		while(temp){
			temp->data->Unlink(node);
			temp = temp->next;
		}

		int pos = nodes.GetPosByData(node);
		if(dealloc) delete(node);
		else node->links.Clear(); // Unlink all nodes.
		nodes.RemoveFromPos(pos);
	}
}

void Graph::RemoveNode(GraphNode *nd, bool dealloc){
	LinkedList_Node<GraphNode*> *temp = nodes.head;
	while(temp){
		temp->data->Unlink(nd);
		temp = temp->next;
	}
	int pos = nodes.GetPosByData(nd);
	if(dealloc) delete(nd);
	else nd->links.Clear(); // Unlink all nodes.
	nodes.RemoveFromPos(pos);
}

void Graph::LinkNodes(int nd1, int nd2, float length){
	GraphNode *node1 = GetPointerByID(nd1);
	if(!node1) return;
	GraphNode *node2 = GetPointerByID(nd2);
	if(!node2) return;
	LinkNodes(node1, node2, length);
}

void Graph::LinkNodes(GraphNode *nd1, GraphNode *nd2, float length){
	GraphNode *node = GetPointerByID(nd1->nodeID);
	GraphNode *node2 = GetPointerByID(nd2->nodeID);
	if(node && node2){
		nd1->Link(nd2, length);
	}
}

void Graph::UnlinkNodes(int nd1, int nd2){
	GraphNode *node1 = GetPointerByID(nd1);
	if(node1 == NULL) return;
	GraphNode *node2 = GetPointerByID(nd2);
	if(node2 == NULL) return;
	UnlinkNodes(node1, node2);
}

void Graph::UnlinkNodes(GraphNode *nd1, GraphNode *nd2){
	nd1->Unlink(nd2);
}

GraphNode *Graph::GetPointerByID(int ndID){
	LinkedList_Node<GraphNode*> *temp = nodes.head;
	while(temp){
		if(temp->data->nodeID == ndID) return temp->data;
		temp = temp->next;
	}
	return NULL;
}

void Graph::PrintAllNodes(){
	LinkedList_Node<GraphNode*> *temp = nodes.head;
	if(!temp) printf("Empty\n");
	while(temp){
		temp->data->PrintAll();
		temp = temp->next;
	}
}
