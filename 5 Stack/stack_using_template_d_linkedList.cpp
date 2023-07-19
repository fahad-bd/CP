//stack using doubly linked list

#include<bits/stdc++.h>
using namespace std;

template <class T>
class node{
    public:
    T data;
    node* next;
    node* previous;
};

template <class T>
class DoublyLinkedList{
    public:
    node<T> * head;
    int Size;

    DoublyLinkedList()
    {
        head = NULL;
        Size = 0;
    }
    
    //create a new with given data O(1)
    node<T> * CreateNewNode(T data)
    {
        node<T> *newNode = new node<T>;
        newNode->data = data;
        newNode->next = NULL;
        newNode->previous = NULL;

        return newNode;
    }

    //insert data at head O(1)
    void InsertAtHead(T data)
    {
        Size++;
        node<T> *newNode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newNode;
            return;
        }

        node<T> *x = head;
        newNode->next = head;
        x->previous = newNode;
        head = newNode;
    }

    //delete head O(1)
    void DeleteAtHead()
    {
        if(head == NULL)
        {
            cout<<"LinkedList is empty!\n";
            return;
        }
        node<T> *a = head;
        node<T> *b = head->next;

        if(b!=NULL){
            b->previous = NULL;
            head = b;
        }
        delete a;
        Size--;
    }

    //print all value O(n)
    void Traverse()
    {
        node<T> *a = head;
        while(a != NULL)
        {
            cout<<a->data<<" ";
            a = a->next;
        }
        cout<<'\n';
    }

    //print size O(1)
    int getSize()
    {
        return Size;
    }
};


//stack class
template<class T>
class Stack
{
public:
    DoublyLinkedList<T> dl;
    Stack()
    {

    }

    void top()
    {
        if(dl.getSize() == 0)
        {
            cout<<"Stack is empty!"<<'\n';
            return;
        }
        cout<<dl.head->data<<'\n';
    }

    void push(T value)
    {
        dl.InsertAtHead(value);
    }

    void pop()
    {
        if(dl.getSize() == 0)
        {
            cout<<"Stack is empty!"<<'\n';
            return;
        }
        dl.DeleteAtHead();
    }

};

int main()
{
    Stack<char> st;
    st.push('a');
    st.top();
    st.push('b');
    st.top();
    st.pop();
    st.top();
    st.pop();
    st.pop();
    return 0;
}