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

void AddFirst (Node*& head, int data) {
	Node* newNode = new Node(data);
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

void printAddress(Node* iter) {
	while( iter != NULL ) {
		cout << iter->next << ' ';
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

void insertNodeAtTail(Node*& head, int data) {
	if( head == NULL ) {
		head = new Node(data);
		return;
	}
	
	Node* iter = head;
	
	while ( iter->next != NULL) {
		iter = iter->next;
	}
	iter->next = new Node(data);
}

void insertNode(Node* node, int data) {
	Node* newNode = new Node(data);
	
	newNode->next = node->next;
	node->next = newNode;
}

void insertNodeAtPosition(Node*& head, int data, int position) {
	Node* iter = head;
	if(position == 0 ) {
		AddFirst(head, data);
		return;
	}
	int i = 1;
	while( i != position ) {
		iter = iter->next;
		i++;
	}
	insertNode(iter, data);
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

bool compare_lists( Node* head1, Node* head2 ) {
	Node* iter1 = head1;
	Node* iter2 = head2;
	while( true ) {
		if( iter1 == NULL && iter2 == NULL ) return true;
		else if( iter1 == NULL || iter2 == NULL ) return false;
		
		if( iter1->data != iter2->data ) return false;
		
		iter1 = iter1->next;
		iter2 = iter2->next;
	}
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

Node* mergeLists( Node* head1, Node* head2 ) {
	Node* head = NULL;
	Node* iter1 = head1;
	Node* iter2 = head2;
	
	bool increase = true;
	
	
	while( iter1->next != NULL ) {
		iter1 = iter1->next;
	}
	while( iter2->next != NULL ) {
		iter2 = iter2->next;
	}
	
	if( head1->data < iter1->data ) increase = true;
	
	else if( head1->data > iter1->data ) increase = false;
	
	else {
		if( head2->data < iter2->data ) increase = true;
		else if( head2->data > iter2->data ) increase = false;
	}
	
	iter1 = head1;
	iter2 = head2;
	
	if( increase ) while( true ) {
		if( iter1 == NULL ) {
			while( iter2 != NULL ) {
				insertNodeAtTail(head, iter2->data);
				iter2 = iter2->next;
			}
			break;
		}
		else if( iter2 == NULL ) {
			while( iter1 != NULL ) {
				insertNodeAtTail(head, iter1->data);
				iter1 = iter1->next;
			}
			break;
		}
		
		if( iter1->data < iter2->data ) {
			insertNodeAtTail(head, iter1->data);
			iter1 = iter1->next;
		}
		else {
			insertNodeAtTail(head, iter2->data);
			iter2 = iter2->next;
		}
	}
	else while( true ) {
		if( iter1 == NULL ) {
			while( iter2 != NULL ) {
				insertNodeAtTail(head, iter2->data);
				iter2 = iter2->next;
			}
			break;
		}
		else if( iter2 == NULL ) {
			while( iter1 != NULL ) {
				insertNodeAtTail(head, iter1->data);
				iter1 = iter1->next;
			}
			break;
		}
		
		if( iter1->data > iter2->data ) {
			insertNodeAtTail(head, iter1->data);
			iter1 = iter1->next;
		}
		else {
			insertNodeAtTail(head, iter2->data);
			iter2 = iter2->next;
		}
	}
	
	return head;
}

Node* insert( Node* head, int data ) {
	if( head == NULL ) {
		head = new Node(data);
		return head;
	}
	if( head->next == NULL ) {
		if( head->data < data ) insertNodeAtTail(head, data);
		else AddFirst(head, data);
		return head;
	}
	
	if( data < head->data ) {
		AddFirst(head, data);
		return head;
	}
	
	Node* iter1 = head;
	Node* iter2 = head->next;
	
	while( iter2 != NULL ) {
		
		if( iter1->data <= data && data <= iter2->data ) {
			insertNode(iter1, data);
			return head;
		}
		
		iter1 = iter1->next;
		iter2 = iter2->next;
	}
	insertNode(iter1, data);
	return head;
}

Node* convert(Node* head)
{
    // Your code here
    
    if( head == NULL ) return head;
    if( head->next->next == NULL ) return head;
    
    Node* iter1 = head;
    Node* iter2 = head->next;
    while( iter2->next != NULL ) {
        iter1 = iter1->next;
        iter2 = iter2->next->next;
    }
    
    
    cout << 1 << endl;
    
    Node* a1 = head;
    Node* a2 = a1->next;
    Node* b1 = iter1->next;
    iter1->next = NULL;
    Node* b2 = b1->next;
    
    while( a2 != NULL ) {
        a1->next = b1;
        b1->next = a2;
        a1 = a2;
        a2 = a2->next;
        b1 = b2;
        b2 = b2->next;
        cout << 1 << endl;
    }
    
    a1->next = b1;
    
    return head;
}

int main() {
	
	Node* head = init_LinkedList(6);
	
	head = convert(head);
	
	print(head);
	
	return 0;
}
