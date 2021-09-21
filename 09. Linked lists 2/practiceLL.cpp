#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
class LinkedList{
    private:
    Node *first;
    public:
    LinkedList() {first = NULL;}
    LinkedList(int a[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};