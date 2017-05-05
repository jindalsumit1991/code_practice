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

ptr deleteNodeAtPos(ptr &head, int pos)
{
    if(!head)
        return head;
    ptr temp = head;
    ptr parent = head;
    if(pos == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;
    while(temp && (count != pos))
    {
        parent = temp;
        temp = temp->next;
        count++;
    }
    if(count == pos)
    {
        cout << "parent: " << parent->data << endl;
        cout << "temp: " << temp->data << endl;
        parent->next = temp->next;
        delete temp;
        return head;
    }
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

   int pos;
   cout << "Enter position to delete node: ";
   cin >> pos;
   cout << "Original list: "<< endl;
   printList(head);
   deleteNodeAtPos(head, pos);
   cout << "List after deleting node: "<< endl;
   printList(head);

   return 0;
}
