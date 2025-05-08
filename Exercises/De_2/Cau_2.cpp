#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* next;
};

void print(Node* head) {
	for(Node* iter = head; iter != NULL; iter = iter->next) {
		cout << iter->value << ' ';
	}
	cout << endl;
}

Node* init_Node(int value = 0) {
	Node* ptr = new Node;
	ptr->value = value;
	ptr->next = NULL;
	return ptr;
}

void insertNodeAtTail(Node*& head, int value) {
	if( head == NULL ) {
		head = init_Node(value);
		return;
	}
	
	Node* iter = head;
	
	while ( iter->next != NULL) {
		iter = iter->next;
	}
	iter->next = init_Node(value);
}

Node* init_LinkedList( int n ) {
	Node* head = NULL;
	
	for(int i = 1; i <= n; i++) {
		int value;
		cin >> value;
		insertNodeAtTail(head, value);
	}
	return head;
}

Node* deleteTop(Node* head) {
	if( head->value > 2 * head->next->value ) {
		Node* oldhead = head;
		head = head->next;
		delete oldhead;
		return head;
	}
	
	Node* prevIter = head;
	Node* currIter = head->next;
	Node* nextIter = currIter->next;
	
	while( nextIter != NULL ) {
		
		
		
		if( currIter->value > 2 * (prevIter->value + nextIter->value) ) {
			prevIter->next = currIter->next;
			delete currIter;
			return head;
		}
		
		
		prevIter = prevIter->next;
		currIter = currIter->next;
		nextIter = nextIter->next;
	}
	
	if( currIter->value > 2 * prevIter->value ) {
		delete currIter;
		prevIter->next = NULL;
		return head;
	}
	return head;
}
