#include <iostream>

using namespace std;

struct node {
   int data;
   node *next;

   node(){}
};

typedef node* ptr;

void push(node **head, int data) {
   node *n = new node();
   n->data = data;
   if(*head == NULL) {
      *head = n;
      n->next = NULL;
   }
   else {
      n->next = *head;
      *head = n;
   }
}

void printList(node* head) {
   if(head == NULL)
      cout<<"List is empty"<<endl;
   else {
      //cout<<endl<<"List is: ";
      while(head) {
	 if(head->next)
	    cout<<head->data<<"->";
	 else
	    cout<<head->data<<"->NULL";
	 head = head->next;
      }
      cout<<endl;
      cout<<endl;
   }
}

void append(node **head, int data) {
   node *n = new node();
   n->data = data;
   n->next = NULL;
   if(*head == NULL)
      *head = n;
   else {
      node *temp = *head;
      while(temp->next) 
	 temp=temp->next;
      temp->next = n;
   }
}

void reverseList(node **head) {
   node *prev = NULL;
   node *current = *head;
   node *next;

   while(current) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
   }
   *head = prev;
}

void recursiveReverse(node **head) {
   node *first;
   node *rest;
   if(*head == NULL)
      return;
   first = *head;
   if(first->next == NULL)
      return;
   rest = first->next;
   recursiveReverse(&rest);
   first->next->next = first;
   first->next = NULL;
   *head = rest;
}

//Swap nodes without swapping data
void swapNodes(node *head, int key1, int key2)
{
    node *node1, *node2, *temp, *prev1, *prev2;
    node1 = head;
    node2 = temp = head;
    bool found1 = false;
    bool found2 = false;
    while(temp)
    {
        if(!found1 && temp->next->data == key1)
        {
            prev1 = temp;
            node1 = temp->next;
            found1 = true;
        }
        if(!found2 && temp->next->data == key2)
        {
            prev2 = temp;
            node2 = temp->next;
            found2 = true;
        }
        if(found1 && found2)
            break;
        temp = temp->next;
    }
    temp = node1->next;
    prev1->next = node2;
    prev2->next = node1;
    node1->next = node2->next;
    node2->next = temp;
}

node *sortedMerge(node *p, node *q, ptr & sorting)
{
    node *new_head = NULL;
    if(!p)
        return q;
    if(!q)
        return p;
    if(p && q)
    {
        if(p->data <= q->data)
        {
            sorting = p;
            p = sorting->next;
        }
        else
        {
            sorting = q;
            q = sorting->next;
        }
    }
    new_head = sorting;

    while(p && q)
    {
        if(p->data < q->data)
        {
            sorting->next = p;
            sorting = p;
            p = sorting->next;
        }
        else
        {
            sorting->next = q;
            sorting = q;
            q = sorting->next;
        }
    }
    if(!p)
        sorting->next = q;
    if(!q)
        sorting->next = p;
    return new_head;
}

int main() {

   node *head1 = NULL;
   append(&head1,1);
   append(&head1,2);
   append(&head1,6);
   append(&head1,8);
   append(&head1,10);
   cout << "List 1: ";
   printList(head1);

   node *head2 = NULL;
   append(&head2,3);
   append(&head2,4);
   append(&head2,5);
   append(&head2,7);
   append(&head2,9);
   cout << "List 2: ";
   printList(head2);
   node *sorting = new node();
   node *head3 = NULL;
   head3 = sortedMerge(head2, head1, sorting);
   cout << "Sorted List: ";
   printList(head3);

   return 0;
}
