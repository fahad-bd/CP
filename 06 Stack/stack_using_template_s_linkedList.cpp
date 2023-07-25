//stack using singly linked list
#include<bits/stdc++.h>
using namespace std;

template<class T>
class node{
    public:
    T data;
    node *next;
};

template<class T>
class SinglyLinkedList{
    public:
    node<T> *head;
    int Size;

    SinglyLinkedList()
    {
        head = NULL;
        Size = 0;
    }

    node<T> *CreateNewNode(T data)
    {
        node<T> *newNode = new node<T>;
        newNode->data = data;
        newNode->next = NULL;

        return newNode;
    }

    void InsertAtHead(T data)
    {
        Size++;
        node<T> *newNode = CreateNewNode(data);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        node<T> *temp = head;
        newNode->next = head;
        head = newNode;
    }

    void DeleteAtHead()
    {
        if(head == NULL)
        {
            cout<<"List is empty!\n";
            return;
        }
        node<T> *temp = head;
        if(head->next != NULL)
        {
            head = head->next;
        }
        delete temp;
        Size--;
    }

    void Traverse()
    {
        node<T> *temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<"\n";
            temp = temp->next;
        }
    }

    int getSize()
    {
        return Size;
    }
};

template<class T>
class Stack
{
    public:
    SinglyLinkedList<T> li;
    Stack(){

    }

    T top()
    {
        if(li.getSize() == 0)
        {
            cout<<"Stack is empty!\n";
            T temp;
            return temp;
        }
        return li.head->data;
    }

    void push(T value)
    {
        li.InsertAtHead(value);
    }

    void pop()
    {
        if(li.getSize() == 0)
        {
            cout<<"Stack is empty!\n";
            return;
        }
        li.DeleteAtHead();
    }
};

int main()
{
    Stack<char> st;
    st.push('a');
    cout<<st.top()<<'\n';
    st.push('b');
    cout<<st.top()<<'\n';
    st.pop();
    cout<<st.top()<<'\n';
    st.pop();
    st.pop();
    return 0;
}