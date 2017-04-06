#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node *next;

    node():next(NULL)
    {}
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

void insertSorted(ptr &head, int data)
{
    ptr newnode = new node();
    newnode->data = data;
    if(!head)
    {
        head = newnode;
        newnode->next = NULL;
        return;
    }
    ptr temp = head;
    while(temp && temp->next)
    {
        if(temp->next->data > data)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        temp = temp->next;
    }
    if(temp)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}


int main() {

   ptr head = NULL;
   append(head,1);
   append(head,2);
   append(head,3);
   append(head,4);
   append(head,8);
   cout << "List : ";
   printList(head);
   insertSorted(head, 5);
   cout << "After inserting 5,6,10,-1 : ";
   insertSorted(head, 6);
   //insertSorted(head, 10);
   printList(head);

   return 0;
}
