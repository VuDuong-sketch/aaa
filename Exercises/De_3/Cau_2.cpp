#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* initNode(int data) {
	Node* ptr = new Node;
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}


struct LinkedList {
	Node* head;
	Node* tail;
	LinkedList* createEvenList();
};

void AddLast(LinkedList* ptr, int data) {
	if( ptr->tail == NULL ) {
		ptr->tail = initNode(data);
		ptr->head = ptr->tail;
		return;
	}
	
	ptr->tail->next = initNode(data);
	ptr->tail = ptr->tail->next;
}

LinkedList* LinkedList::createEvenList() {
	LinkedList* ptr = new LinkedList;
	ptr->head = NULL;
	ptr->tail = NULL;
	
	if( head == NULL || head->next == NULL ) return ptr;
	for(Node* iter = head->next;; iter = iter->next->next) {
		AddLast(ptr, iter->data);
		if( iter->next == NULL || iter->next->next == NULL) return ptr;
		
	}
	return ptr;
	
}
