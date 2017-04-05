#include <iostream>

using namespace std;

struct node {
   int data;
   node *next;

   node(){}
};

typedef node* ptr;

void push(ptr &head, int data) {
   node *n = new node();
   n->data = data;
   if(head == NULL) {
      head = n;
      n->next = NULL;
   }
   else {
      n->next = head;
      head = n;
   }
}

void printList(ptr head) {
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

void append(ptr &head, int data) {
    node *n = new node();
    n->data = data;
    n->next = NULL;
    if(head == NULL)
        head = n;
    else {
        node *temp = head;
        while(temp->next) 
            temp=temp->next;
        temp->next = n;
    }
}

node *sortedMerge(ptr p, ptr q)
{
    ptr sorting, new_head;
    sorting = new_head = NULL;
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

void splitList(ptr head, ptr &firstHalf, ptr &secondHalf)
{
    if(head==NULL || head->next==NULL)
    {
        firstHalf = head;
        secondHalf = NULL;
    }
    else
    {
        ptr slow, fast;
        slow = head;
        fast = head->next;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        firstHalf = head;
        secondHalf = slow->next;
        slow->next = NULL;
    }
}

void mergeSort(ptr &headref)
{
    ptr head = headref;
    ptr a,b;
    if(head == NULL || head->next == NULL)
        return;

    splitList(head,a,b);
    mergeSort(a);
    mergeSort(b);

    headref = sortedMerge(a,b);
}

int main() {

   node *head1 = NULL;
   append(head1,1);
   append(head1,2);
   append(head1,6);
   append(head1,8);
   append(head1,10);
   cout << "List 1: ";
   printList(head1);

   node *head2 = NULL;
   append(head2,3);
   append(head2,4);
   append(head2,5);
   append(head2,7);
   append(head2,9);
   cout << "List 2: ";
   printList(head2);
   node *head3 = NULL;
   head3 = sortedMerge(head2, head1);
   cout << "Sorted List: ";
   printList(head3);
   mergeSort(head3);
   cout << "List after merge sort: ";
   printList(head3);

   return 0;
}
