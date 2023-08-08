
/*
      Optimised Approach
            - T(N) = O(N)
            - S(N) = O(1)
*/

Node *findMiddle(Node *head) 
{
  if( head == NULL || head->next == NULL )
  {
    return head;
  }
  Node* slow = head;
  Node* fast = head->next;
  while( fast != NULL )
  {
    fast = fast->next;
    if( fast != NULL )
    {
      fast = fast->next;
    }
    slow = slow->next;
  }
  return slow;
}




/*
      BRUTE FORCE SOLUTION -> Find the length, then find the node
                            - T(N) = O(N) + O(n/2)
                            - S(N) = O(1)
*/


int getLength( Node* &head )
{
  Node* temp = head;
  int count = 0;
  while( temp != NULL )
  {
    count++;
    temp = temp->next;
  }
  return count;
}


Node *findMiddle(Node *head) {
    int len = getLength(head);
    int ans = (len/2);
    
    Node* temp = head;
    int count = 0;
    while( count < ans )
    {
      temp = temp->next;
      count++;
    }
    return temp;
}

