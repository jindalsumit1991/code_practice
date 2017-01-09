#include <iostream>

using namespace std;

struct node {
   int data;
   node *next;
};

typedef node* head;

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
      cout<<endl<<"List is: ";
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

void addAfter(node **head,int after, int data) {
   if(*head == NULL) {
      cout<<"List is empty"<<endl;
      return;
   }
   else {
      node *n = new node();
      n->data = data;
      node *temp = *head;
      while (temp) {
	 if(temp->data == after) {
	    n->next = temp->next;
	    temp->next = n;
	    return;
	 }
	 temp = temp->next;
      }
      cout<<"\nNode "<<after<<" does not exist\n"<<endl;
   }
}

void addBefore(node **head,int before, int data) {
   if(*head == NULL) {
      cout<<"List is empty"<<endl;
      return;
   }
   else {
      node *n = new node();
      n->data = data;
      node *temp = *head;
      while (temp->next) {
	 if(temp->next->data == before) {
	    n->next = temp->next;
	    temp->next = n;
	    return;
	 }
	 temp = temp->next;
      }
      cout<<"\nNode "<<before<<" does not exist\n"<<endl;
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
int main() {

   node *head = NULL;
   push(&head,1);
   push(&head,2);
   push(&head,3);
   push(&head,4);
   append(&head,5);
   addAfter(&head,20,90);
   addAfter(&head,3,90);
   printList(head);
   addBefore(&head,90,80);
   printList(head);
   reverseList(&head);
   printList(head);
   return 0;
}
