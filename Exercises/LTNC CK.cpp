#include <iostream>

using namespace std;

int n, count = 0;
int** array;

// Cau 2:
struct Node {
	int value;
	Node* next;
};

Node* initNode(int data) {
	Node* p = new Node;
	p->value = data;
	p->next = NULL;
}

void insertNodeAtTail(Node*& head, int data) {
	if( head == NULL ) {
		head = initNode(data);
		return;
	}
	
	Node* iter = head;
	
	while ( iter->next != NULL) {
		iter = iter->next;
	}
	iter->next = initNode(data);
}

Node* init_LinkedList( int n ) {
	Node* head = NULL;
	
	for(int i = 1; i <= n; i++) {
		int data;
		cin >> data;
		insertNodeAtTail(head, data);
	}
	return head;
}

void print(Node*& head) {
	for(Node* iter = head; iter != NULL; iter = iter->next) {
		cout << iter->value << ' ';
	}
	cout << endl;
}

void deleteNode ( Node*& head, Node* p ) {
	if( head == NULL ) return;
	if( head->next == NULL ) {
		head = NULL;
		delete p;
		return;
	}
	if( p == head ) {
		head = head->next;
		delete p;
		return;
	}
	for( Node* iter = head;; iter = iter->next ) {
		if( iter->next == p ) {
			iter->next = p->next;
			delete p;
			return;
		}
	}
}

Node* deleteBottom ( Node* head ) {
	if( head == NULL ) return head;
	if( head->next == NULL ) return head;
	if( head->next->next == NULL ) {
		if( head->value * 2 < head->next->value ) deleteNode(head, head);
		else if( head->next->value * 2 < head->value ) deleteNode(head, head->next);
		return head;
	}
	
	if( head->value * 2 < head->next->value ) {
		deleteNode(head, head);
		return head;
	}
		
	
	Node* prevIter = head;
	Node* iter = head->next;
	Node* nextIter = head->next->next;
	
	while( nextIter != NULL ) {
		if( iter->value * 2 < ( prevIter->value < nextIter->value ? prevIter->value : nextIter->value ) ) {
			deleteNode(head, iter);
			return head;
		}
		prevIter = prevIter->next;
		iter = iter->next;
		nextIter = nextIter->next;
	}
	if( iter->value * 2 < prevIter->value ) {
		deleteNode(head, iter);
		return head;
	}
}

bool Visited[100][100];

bool visited(int i, int j) {
	if(i == -1 || i == n || j == -1 || j == n) return 1;
	return Visited[i][j];
}

int a(int i, int j) {
	if(i == -1 || i == n || j == -1 || j == n) return 1;
	return array[i][j];
}

void DFS(int** array, int i, int j) {
	count++;
	Visited[i][j] = true;
		
	if( !( a(i,j+1)==1 || visited(i,j+1) ) ){
		DFS(array, i, j+1);
	}
	if( !( a(i,j-1)==1 || visited(i,j-1) ) ){
		DFS(array, i, j-1);
	}
	if( !( a(i+1,j)==1 || visited(i+1,j) ) ){
		DFS(array, i+1, j);
	}
	if( !( a(i-1,j)==1 || visited(i-1,j) ) ){
		DFS(array, i-1, j);
	}
}

int main() {
	
	// Cau 1:
	
	
	// Cau 3:
	cin >> n;
	array = new int*[n];
	for(int i = 0; i < n; i++) array[i] = new int[n];
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}
	
	Area(array, 0, 0);
	cout << count;
	
	
	return 0;
}
