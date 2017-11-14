#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<stdlib.h>
#include<iostream>


template<typename T>
struct LinkedList_Node {
public:
	T data;
	LinkedList_Node<T> *prev;
	LinkedList_Node<T> *next;

	LinkedList_Node<T>(T data) : data(data) {
		prev = NULL;
		next = NULL;
	}

	~LinkedList_Node<T>(){
		prev = NULL;
		next = NULL;
	}
};

template<typename T>
class LinkedList {
private:
	int count;
public:
	LinkedList_Node<T> *head;
	LinkedList_Node<T> *tail;

	// CONSTRUCT
	LinkedList();
	~LinkedList();

	// ADD
	void AddAtTail(T data);
	void AddAtHead(T data);
	void AddAtPos(T data, int pos);

	// REMOVE
	void RemoveFromTail();
	void RemoveFromHead();
	void RemoveFromPos(int pos);
	void Clear();

	// GET
	T GetFromPos(int pos);
	int GetPosByData(T data);
	int Length();

	// OTHERS
	bool Contains(const T& data);
};

template<typename T>
LinkedList<T>::LinkedList(){
	count = 0;
	head = NULL;
	tail = NULL;
};

template<typename T>
LinkedList<T>::~LinkedList(){
	Clear();
};

// ADD
template<typename T>
void LinkedList<T>::AddAtTail(T data){
	LinkedList_Node<T> *node = new LinkedList_Node<T>(data);
	if(count > 0){
		tail->next = node;
		node->prev = tail;
		tail = node;
	} else if (count == 0){
		tail = node;
		head = node;
	}
	count++;
};

template<typename T>
void LinkedList<T>::AddAtHead(T data){
	LinkedList_Node<T> *node = new LinkedList_Node<T>(data);
	if(count > 0){
		head->prev = node;
		node->next = head;
		head = node;
	} else if (count == 0){
		tail = node;
		head = node;
	}
	count++;
};

template<typename T>
void LinkedList<T>::AddAtPos(T data, int pos){
	if(pos == 0) return AddAtHead(data);
	if (pos == count) return AddAtTail(data);
	if(pos < count && pos > 0){
		LinkedList_Node<T> *temp = head;
		int i=0;
		while(i<pos){
			i++;
			temp = temp->next;
		}
		LinkedList_Node<T> *node = new LinkedList_Node<T>(data);
		temp->prev->next = node;
		node->prev = temp->prev;
		node->next = temp;
		temp->prev = node;
		count++;
	}
};

// REMOVE
template<typename T>
void LinkedList<T>::RemoveFromTail(){
	if(count > 1){
		tail = tail->prev;
		delete(tail->next);
		tail->next = NULL;
		count--;
	} else if(count == 1){
		delete(tail);
		tail = NULL;
		head = NULL;
		count--;
	}
};

template<typename T>
void LinkedList<T>::RemoveFromHead(){
	if(count > 1){
		head = head->next;
		delete(head->prev);
		head->prev = NULL;
		count--;
	} else if(count == 1){
		count--;
		delete(head);
		head = NULL;
		tail = NULL;
	}
};

template<typename T>
void LinkedList<T>::RemoveFromPos(int pos){
	if(pos == 0) return RemoveFromHead();
	if (pos == count-1) return RemoveFromTail();
	if(pos < count-1 && pos > 0){
		LinkedList_Node<T> *temp = head;
		int i=0;
		while(i<pos){
			i++;
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		count--;
		delete(temp);
	}
};

template<typename T>
void LinkedList<T>::Clear(){
	LinkedList_Node<T> *temp;
	while(head){
		temp = head;
		head = head->next;
		delete temp;
	}
	count = 0;
}

// GET
template<typename T>
T LinkedList<T>::GetFromPos(int pos){
	if(pos == 0) return head->data;
	if (pos == count-1) return tail->data;
	if(pos < count-1 && pos > 0){
		LinkedList_Node<T> *temp = head;
		int i=0;
		while(i<pos){
			i++;
			temp = temp->next;
		}
		return temp->data;
	}
};

template<typename T>
int LinkedList<T>::GetPosByData(T data){
	LinkedList_Node<T> *temp = head;
	int i=0;
	while(i<count){
		if(temp->data == data) return i;
		i++;
		temp = temp->next;
	}
	return -1;
};

template<typename T>
int LinkedList<T>::Length(){
	return count;
}


template<typename T>
bool LinkedList<T>::Contains(const T& data){
	LinkedList_Node<T> *nd = head;
	while(nd){
		if(nd->data == data) return true;
		nd = nd->next;
	}
	return false;
};

#endif
