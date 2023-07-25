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

    T top()
    {
        if(dl.getSize() == 0)
        {
            cout<<"Stack is empty!"<<'\n';
            T a;
            return a;
        }
        return dl.head->data;
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

    int getSize()
    {
        return dl.getSize();
    }

    void Traverse()
    {
        dl.Traverse();
    }
};

int main()
{
    Stack<int>st;
    st.push(4);
    st.push(6);
    st.push(3);
    st.push(7);
    st.push(9);
    
    Stack<int>temp;
//O(n^2)
    while(st.getSize() > 0)
    {
        int x = st.top();
        st.pop();

        while(temp.getSize() > 0)
        {
            if(temp.top() < x){
                break;
            }
            st.push(temp.top());
            temp.pop();
        }
        temp.push(x);
    }

    swap(st,temp);
    while (st.getSize() > 0)
    {
        cout<<st.top()<<' ';
        st.pop();
    }
    
    return 0;
}