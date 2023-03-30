#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root;
		int size;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
}

void List::show(){
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

void List::remove(int d){
    Node *n = root;
    if(d == 0){
        root = n->next;
        delete n;
    }
    else if(d == size-1){
        while(n->next){
            n = n->next;
        }
    delete n;
    }
    else{
        Node *Bfdel = root;
        for(int i = 1;i <= d-1;i++){
            Bfdel = Bfdel->next;
        }
        Node *del = root;
        for(int i = 1;i <= d;i++){
            del = del->next;
        }
        Node *Afdel = root;
        for(int i = 1;i <= d+1;i++){
            Afdel = Afdel->next;
        }
        Bfdel->next = Afdel;
        delete del;
    }
}
