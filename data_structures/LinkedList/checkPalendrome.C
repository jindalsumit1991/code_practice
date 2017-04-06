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

void reverse(ptr &head) {
    ptr first;
    ptr rest;
    if(head == NULL)
        return;
    first = head;
    if(first->next == NULL)
        return;
    rest = first->next;
    reverse(rest);
    first->next->next = first;
    first->next = NULL;
    head = rest;
}

bool checkPalindrome(ptr head)
{
    if(!head)
    {
        cout << "List is empty" << endl;
        return false;
    }

    /*Count number of nodes

     * we will reverse the list, starting from half, 
     *  and then compare the first half and second half
     * */
    ptr slow = head;
    ptr fast = slow->next;
    int count = 0;
    while(fast && fast->next)
    {
        count++;
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Mid element is " << slow->data 
        << ", count is " << count << endl;

    /*If count is odd, list has even number of nodes
     * Thus reverse the list just after the mid
     * For 1->2->2->1, reverse after first 2(mid), gettin 1->2->1->2
     * For 1->2->3->2->1, reverse after mid (3), getting 1->2->3->1->2
     */

    ptr secondHead;
    secondHead = slow->next;

    //reverse the second half list
    reverse(secondHead);
    ptr temp1 = secondHead;
    ptr temp2 = head;
    while(temp2 && temp1)
    {
        if(temp1->data != temp2->data)
            return false;
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    return true;
}

bool checkPalindrome_new(ptr head)
{
    if(!head)
    {
        cout << "List is empty" << endl;
        return false;
    }

    /*Count number of nodes

     * we will reverse the list, starting from half, 
     *  and then compare the first half and second half
     * */
    ptr slow = head;
    ptr fast = slow->next;
    int count = 0;
    while(fast && fast->next)
    {
        count++;
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Mid element is " << slow->data 
        << ", count is " << count << endl;

    /*If count is odd, list has even number of nodes
     * Thus reverse the list just after the mid
     * For 1->2->2->1, reverse after first 2(mid), gettin 1->2->1->2
     * For 1->2->3->2->1, reverse after mid (3), getting 1->2->3->1->2
     */

    ptr secondHead;
    secondHead = slow->next;

    //Push the second half list into a stack
    vector<int> v;
    while(secondHead)
    {
        v.push_back(secondHead->data);
        secondHead = secondHead->next;
    }

    ptr temp = head;
    //Compare each element of stack(starting from top) with first list data
    for(auto it = v.end()-1; it >= v.begin(); it--)
    {
        if(*it != temp->data)
            return false;
        temp = temp->next;
    }

   return true;
}

int main() {

   ptr head = NULL;
   append(head,1);
   append(head,2);
   append(head,3);
   append(head,2);
   append(head,1);
   //append(head,5);
   cout << "List : ";
   printList(head);

   if(checkPalindrome(head))
       cout << "Yes, it is a palindrome" << endl;
   else
       cout << "No, it is not a palindrome" << endl;

   return 0;
}
