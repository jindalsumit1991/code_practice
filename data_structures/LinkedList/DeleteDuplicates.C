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

ptr removeDuplicates(ptr head)
{
    if(!head)
        return head;
    ptr temp = head;
    ptr parent = NULL;
    while(temp){
        ptr temp2 = temp;
        while(temp2->data == temp2->next->data)
            temp2 = temp2->next;
        temp->next = temp2->next;   
        temp = temp->next;
    }
    return head;
}

int main() 
{
   ptr head = NULL;
   append(head,1);
   append(head,2);
   append(head,2);
   append(head,3);
   append(head,4);
   append(head,5);
   append(head,6);
   append(head,7);
   append(head,8);
   append(head,9);

   cout << "Original list: "<< endl;
   printList(head);
   head = removeDuplicates(head);
   cout << "List after deleting duplicates: "<< endl;
   printList(head);

   return 0;
}
