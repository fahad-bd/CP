#include<bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node *next;
};

class Queue{
    node *head;
    node *tail;
    int Size;

public:
    Queue(){
        head = NULL;
        tail = NULL;
        Size = 0;
    }

    node *CreateNewNode(int data){
        node *newNode = new node;
        newNode->data = data;
        newNode->next = NULL;

        return newNode;
    }

    void enqueue(int value){
        Size++;
        node *newNode = CreateNewNode(value);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void dequeue()
    {
        if(Size == 0){
            cout<<"Queue is empty\n";
            return;
        }
        if(Size == 1)
        {
            delete head;
            head == NULL;
            tail = NULL;
            Size--;
            return;
        }

        node *temp = head;
        head = head->next;
        delete temp;
        Size--;
    }

    int front()
    {
        if(Size == 0){
            cout<<"Queue is empty\n";
            return -1;
        }
        return head->data;
    }

    int getSize()
    {
        return Size;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<q.getSize()<<endl;

    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;

    cout<<q.getSize()<<endl;
    return 0;
}