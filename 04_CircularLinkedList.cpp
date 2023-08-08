/*
    Circular Linked List
        - Traversal
        - Insertion
        - Deletion
*/

#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* next;
    // Constructor
    Node( int data )
    {
        this->data = data;
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


void print( Node* &tail )
{
    Node* temp = tail;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    while( temp != tail );
    cout<<endl;
}


void insertion( Node* &tail, int element, int data )
{
    if( tail == NULL )
    {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node* temp = tail;
        while( temp->data != element )
        {
            temp = temp->next;
        }
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


int getLength( Node* &tail )
{
    int count = 0;
    Node* temp = tail;
    do{
        temp = temp->next;
        count++;
    }
    while( temp != tail );
    return count;
    cout<<endl;
}


void deletion( Node* &tail , int data )
{
    if( tail == NULL )
    {
        cout<<"LL is empty "<<endl;
        return;
    }
    else
    {
        Node* prev = tail;
        Node* curr = prev->next;
        while( curr->data != data)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main()
{
    Node* tail = NULL;
    
    insertion(tail,1, 1);
    insertion(tail,1, 2);
    insertion(tail,2, 3);
    insertion(tail,3, 4);
    insertion(tail,4, 5);
    print(tail);
    
    deletion(tail, 3);
    print(tail);
    
    cout<<"Length:"<<getLength(tail)<<endl;
    
    return 0;
}
