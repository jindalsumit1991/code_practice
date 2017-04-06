#include <iostream>

using namespace std;

struct node {
   int data;
   node *next;

   node(){}
};

typedef node* ptr;

void push(ptr &head, int data) {
   ptr n = new node();
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
    ptr n = new node();
    n->data = data;
    n->next = NULL;
    if(head == NULL)
        head = n;
    else {
        ptr temp = head;
        while(temp->next) 
            temp=temp->next;
        temp->next = n;
    }
}

ptr sortedMerge(ptr p, ptr q)
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

int main() 
{
   ptr head = NULL;
   append(head,3);
   append(head,2);
   append(head,6);
   append(head,1);
   append(head,10);
   append(head,5);
   append(head,11);
   append(head,4);
   append(head,60);
   append(head,55);
   cout << "Original List: ";
   printList(head);
   mergeSort(head);
   cout << "List after merge sort: ";
   printList(head);

   return 0;
}
