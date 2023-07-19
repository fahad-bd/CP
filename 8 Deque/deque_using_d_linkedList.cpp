// deque double ended queue
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* previous;
};

class Deque{
    public:
    node *head;
    node *tail;
    int Size;

    Deque(){
        head = NULL;
        tail = NULL;
        Size = 0;
    }

    node *CreateNewNode(int value){
        node *newNode = new node;
        newNode->data = value;
        newNode->next = NULL;
        newNode->previous = NULL;

        return newNode;
    }

    //push back O(1)
    void push_back(int value){
        node *newNode = CreateNewNode(value);
        if(Size == 0){
            head = newNode;
            tail = newNode;
            Size++;
            return;
        }

        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        Size++;
    }

    // push fornt O(1)
    void push_front(int value){
        node *newNode = CreateNewNode(value);
        if(Size == 0){
            head = newNode;
            tail = newNode;
            Size++;
            return;
        }

        head->previous = newNode;
        newNode->next = head;
        head = newNode;
        Size++;
    }

    // pop back O(1)
    void pop_back(){
        if(Size == 0){
            cout<<"Deque is empty!\n";
            return;
        }
        if(Size == 1){
            delete tail;
            head = NULL;
            tail = NULL;
            Size--;
            return;
        }

        node *temp = tail;
        tail = tail->previous;
        tail->next = NULL;
        delete temp;
        Size--;
    }

    // pop front
    void pop_front(){
        if(Size == 0){
            cout<<"Deque is empty!\n";
            return;
        }
        if(Size == 1){
            delete tail;
            head = NULL;
            tail = NULL;
            Size--;
            return;
        }

        node *temp = head;
        head = head->next;
        delete temp;
        head->previous = NULL;
        Size--;
    }

    // front O(1)
    int front()
    {
        if(Size == 0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        return head->data;
    }

    // back O(1)
    int back()
    {
        if(Size == 0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        return tail->data;
    }

};

int main()
{
    Deque d;
    d.push_back(5);
    d.push_back(15);
    d.push_back(50);

    cout<<d.front()<<" "<<d.back()<<'\n';
    d.push_front(11);
    cout<<d.front()<<" "<<d.back()<<'\n';
    d.pop_back();
    cout<<d.front()<<" "<<d.back()<<'\n';
    d.pop_front();
    cout<<d.front()<<" "<<d.back()<<'\n';

    return 0;
}