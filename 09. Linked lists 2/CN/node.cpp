#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node (int data) {
        this->data = data;
        next = NULL;
    }
};

Node *takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;            
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head){
    Node *temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//TEST-2
//NEXT LARGER ELEMENTT
Node *helper(Node* head);
Node *nextLargerNumber(Node* head);

//DELETE ALTERNATE NODES
void deleteAlternateNodes(Node* head);


int main(){
    Node *head = NULL;
    head = takeInput();
    deleteAlternateNodes(head);
    print(head);
    return 0;
}


//TEST-2
//NEXT LARGER ELEMENTT
//Next Number
// Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
// Note: You don't need to print the elements, just update the elements and return the head of updated LL.
// Input Constraints:
// 1 <= Length of Linked List <=10^6.
// Input format :
// Line 1 : Linked list elements (separated by space and terminated by -1)
// Output Format :
// Line 1: Updated linked list elements 
// Sample Input 1 :
// 3 9 2 5 -1
// Sample Output 1 :
// 3 9 2 6
// Sample Input 2 :
// 9 9 9 -1
// Sample Output 1 :
// 1 0 0 0 
// *********************************************** SOLUTION **************************************************************************

Node *helper(Node* head) {
    if(head->next == NULL) {
        head->data++;
        return head;
    }
    // We will be getting next larger element from recursion for n-1 nodes except head node
    // 9 9 9    =>    9 10 0
    // (10 0 is received in head->next which is returned by recursion)
    head->next = helper(head->next);
    if(head->next->data > 9) {
        head->next->data = 0;
        head->data++;
    }
    return head;
}
Node *nextLargerNumber(Node* head) {
    head = helper(head);
    //for input as 9 9 9
    //we will be getting 10 0 0 from helper funcion
    //so, we just need to check one condition for the head node
    if(head->data > 9) {
        Node* temp = new Node(1);
        temp->next = head;
        head->data = 0;
        head = temp;
    }
    return head;
}




// Delete alternate nodes
// Given a linked list, delete all alternate nodes in the list. That means given Linked List is -
// 10 20 30 40 50 60 
// you need to delete nodes - 20, 40 and 60
// Note : Head of the list will remain same. Don't need to print or return anything.
// Input Constraints:
// 1 <= Length of Linked List <=10^6.
// Input format :
// Linked list elements (separated by space and terminated by -1)
// Output Format :
// Updated linked list elements 
// Sample Input :
// 1 2 3 4 5 -1
// Sample Output :
// 1 3 5
// *********************************************** SOLUTION **************************************************************************

void deleteAlternateNodes(Node* head) {
    if(head == NULL)
    return;
    Node *prev = head;
    Node *n = head->next;
    while(prev && n) {
        prev->next = n->next;
        free(n);
        prev = prev->next;
        if(prev) {
            n = prev->next;
        }
    }
}
                                                         