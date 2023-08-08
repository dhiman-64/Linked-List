/*
    Doubly Linked List
        - Traversal
        - Insertion
        - Deletion
*/

#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* prev;
        Node* next;
    // Constructor
    Node( int data )
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    // Destructor
    ~Node()
    {
        int value = this->data;
        while( this->next != NULL )
        {
            delete next;
            this->next = NULL;
        }
        cout<<"Free Mem: "<<value<<endl;
    }
};


void print( Node* &head )
{
    Node* temp = head;
    while( temp != NULL )
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


void insertHead( Node* &head, Node* &tail, int data )
{
    if( head == NULL )
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}


void insertTail( Node* &head, Node* &tail, int data )
{
    if( tail == NULL )
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }
}


void insertion( Node* &head, Node* &tail, int position, int data )
{
    if( position == 1)
    {
        insertHead(head, tail, data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while( count < position-1 )
    {
        temp = temp->next;
        count++;
    }
    if( temp->next == NULL )
    {
        insertTail(head,tail, data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}


int getLength( Node* &head )
{
    Node* temp = head;
    int count = 0;
    while( temp != NULL )
    {
        temp = temp->next;
        count++;
    }
    return count;
}


void deleteNode( Node* &head, int position )
{
    if( position == 1 )
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* prev = NULL;
        Node* curr = head;
        int count = 1;
        while( count < position )
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    
    insertHead(head, tail, 0);
    insertHead(head, tail, -10);
    insertHead(head, tail, -20);
    print(head);
    
    cout<<"Length: "<<getLength(head)<<endl;
    
    insertTail(head, tail, 20);
    print(head);
    
    insertion(head, tail, 1, 900);
    insertion(head, tail, 4, 900);
    insertion(head, tail, 8, 900);
    print(head);
    
    cout<<"Length: "<<getLength(head)<<endl;
    
    deleteNode(head, 1);
    deleteNode(head, 3);
    deleteNode(head, 6);
    print(head);
    cout<<"Length: "<<getLength(head)<<endl;
    
    return 0;
}
