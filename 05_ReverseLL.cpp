
/* Iterative Solution
        T(n) = O(n)
        S(n) = O(1)
*/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* forward = NULL;
    while( curr != NULL )
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }  
    return prev;
}



/*
  Recursive Solution
      T(N) = O(N)
      S(N) = O(N)
*/

LinkedListNode<int>* reverseLL( LinkedListNode<int>* &head )
{
    // Base Case
    if( head == NULL || head->next == NULL )
    {
        return head;
    }
    LinkedListNode<int>* chottaHead = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return chottaHead;
}


LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    return reverseLL(head);
}
