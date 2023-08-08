/*
  T(N) = O(N)
  S(N) = O(N/K)
*/


Node* kReverse(Node* head, int k) {

    int size = 0;
    Node* temp = head;
    while( temp != NULL )
    {
        temp = temp->next;
        size++;
    }
    
    if( size < k )
    {
        return head;
    }
    
    if(head == NULL)
    {
        return NULL;
    }

    //Step1 : Reverse K group using iterative
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    while(curr!= NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // Step2 Recursion to do other same step1
    if(next != NULL)
    {
        head->next = kReverse(next, k);
    }
    // Step3 : return head of reversed LL
    return prev;
}
