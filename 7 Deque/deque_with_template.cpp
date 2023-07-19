// deque (double ended queue) using template class
#include<bits/stdc++.h>
using namespace std;

template<class T>
class node{
    public:
    T data;
    node* next;
    node* previous;
};

template<class T>
class Deque{
    public:
    node<T> *head;
    node<T> *tail;
    int Size;

    Deque(){
        head = NULL;
        tail = NULL;
        Size = 0;
    }

    node<T> *CreateNewNode(T value){
        node<T> *newNode = new node<T>;
        newNode->data = value;
        newNode->next = NULL;
        newNode->previous = NULL;

        return newNode;
    }

    //push back O(1)
    void push_back(T value){
        node<T> *newNode = CreateNewNode(value);
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
    void push_front(T value){
        node<T> *newNode = CreateNewNode(value);
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

        node<T> *temp = tail;
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

        node<T> *temp = head;
        head = head->next;
        delete temp;
        head->previous = NULL;
        Size--;
    }

    // front O(1)
    T front()
    {
        if(Size == 0)
        {
            cout<<"Deque is empty\n";
            T temp;
            return temp;
        }
        return head->data;
    }

    // back O(1)
    T back()
    {
        if(Size == 0)
        {
            cout<<"Deque is empty\n";
            T temp;
            return temp;
        }
        return tail->data;
    }

};

int main()
{
    Deque<int> d;
    d.push_back(5);
    d.push_back(15);
    d.push_back(50);

    cout<<"Fornt: "<<d.front()<<" Back: "<<d.back()<<'\n';
    d.push_front(11);
    cout<<"Fornt: "<<d.front()<<" Back: "<<d.back()<<'\n';
    d.pop_back();
    cout<<"Fornt: "<<d.front()<<" Back: "<<d.back()<<'\n';


    Deque<char> dc;
    dc.push_back('f');
    dc.push_front('a');
    cout<<"Fornt: "<<dc.front()<<" Back: "<<dc.back()<<'\n';


    return 0;
}