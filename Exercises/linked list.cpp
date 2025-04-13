#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	
	Node (int _data, Node* _next = NULL) {
		data = _data;
		next = _next;
	}
};

void AddFirst (Node*& head, int n) {
	Node* newNode = new Node(n);
	newNode->next = head;
	head = newNode;
}

void print(Node* iter) {
	while( iter != NULL ) {
		cout << iter->data << ' ';
		iter = iter->next;
	}
	cout << endl;
}

void recursionPrint(Node* iter) {
		
	iter = iter->next;
	if( iter == NULL ) return;
	recursionPrint(iter);
	
	cout << iter->data << ' ';
	
}

void reversePrint(Node* head) {
	recursionPrint(head);
	cout << head->data << endl;
}

Node* insertNodeAtTail(Node* head, int n) {
	if( head == NULL ) {
		head = new Node(n);
		return head;
	}
	
	Node* iter = head;
	
	while ( iter->next != NULL) {
		iter = iter->next;
	}
	iter->next = new Node(n);
	return head;
}

void insertNode(Node* node, int n) {
	Node* newNode = new Node(n);
	
	newNode->next = node->next;
	node->next = newNode;
}

void insertNodeAtPosition(Node*& head, int n, int position) {
	Node* iter = head;
	if(position == 0 ) {
		AddFirst(head, n);
		return;
	}
	int i = 1;
	while( i != position ) {
		iter = iter->next;
		i++;
	}
	insertNode(iter, n);
}

void deleteNode(Node*& head, int position) {
	if( position == 0) {
		Node* oldNode = head;
		head = head->next;
		delete oldNode;
		return;
	}
	Node* iter = head;
	int i = 1;
	while ( i != position ) {
		iter = iter->next;
		i++;
	}
	Node* oldNode = iter->next;
	iter->next = (iter->next)->next;
	delete oldNode;
}

void reverse(Node*& head) {
	Node* a = head;
	Node* b = a->next;
	Node* c = b->next;
	a->next = NULL;
	while( c != NULL ) {
		b->next = a;
		a = b;
		b = c;
		c = c->next;
		head = a;
	}
	b->next = a;
	a = b;
	head = a;
}

int main() {
	
	Node* head = NULL;
	
	head = insertNodeAtTail(head, 10);
	AddFirst(head, 2);
	AddFirst(head, 3);
	AddFirst(head, 4);
	AddFirst(head, 5);
	AddFirst(head, 6);
	
	head = insertNodeAtTail(head, 0);
	
	insertNodeAtPosition(head, 99, 3);
	
	deleteNode(head, 4);
	
	print(head);
	
	reversePrint(head);
	
	reverse(head);
	print(head);
	
	return 0;
}
