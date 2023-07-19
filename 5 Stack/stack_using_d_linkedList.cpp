//stack using doubly linked list

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* previous;
};

class DoublyLinkedList{
    public:
    node* head;
    int Size;

    DoublyLinkedList()
    {
        head = NULL;
        Size = 0;
    }
    
    //create a new with given data O(1)
    node* CreateNewNode(int data)
    {
        node* newNode = new node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->previous = NULL;

        return newNode;
    }

    //insert data at head O(1)
    void InsertAtHead(int data)
    {
        Size++;
        node* newNode = CreateNewNode(data);
        if(head == NULL)
        {
            head = newNode;
            return;
        }

        node* x = head;
        newNode->next = head;
        x->previous = newNode;
        head = newNode;
    }

    //Insert the given data at the given index O(n)
    void Insert(int index, int data)
    {
        if(index >  Size || index < 0)
        {
            return;
        }

        if(index == 0)
        {
            InsertAtHead(data);
            return;
        }

        node *a = head;
        int current_index = 0;

        while(current_index != index-1)
        {
            a = a->next;
            current_index++;
        }

        node *newNode = CreateNewNode(data);
        newNode->next = a->next;
        newNode->previous = a;

        node *b = a->next;
        b->previous = newNode;
        a->next = newNode;

        Size++;
    }

    //delete head O(1)
    void DeleteAtHead()
    {
        if(head == NULL)
        {
            cout<<"LinkedList is empty!\n";
            return;
        }
        node *a = head;
        node *b = head->next;

        if(b!=NULL){
            b->previous = NULL;
            head = b;
        }
        delete a;
        Size--;
    }

    //delete O(n)
    void Delete(int index)
    {
        if(index < 0 || index > Size) {
            cout<<index<<" doesn't exist.\n";
            return;
        }

        node *a = head;
        int current_index = 0;
        while(current_index != index)
        {
            a = a->next;
            current_index++;
        }

        node *b = a->previous;
        node *c = a->next;

        if(b != NULL) b->next = c;
        if(c != NULL) c->previous = b;

        if(index == 0) head = c;
        delete a;
        Size--;
    }

    //reverse, for reverse swap previous and next pointer for each node O(n)
    void Reverse()
    {
        if(head == NULL) return;

        node *a = head;
        int current_index = 0;
        while(current_index != Size-1)
        {
            a = a->next;
            current_index++;
        }
        //last index is in a

        node *b = head;
        while(b != NULL)
        {
            swap(b->next, b->previous);
            b = b->previous;
        }
        head = a;
    }

    //print all value O(n)
    void Traverse()
    {
        node *a = head;
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
class Stack
{
public:
    DoublyLinkedList dl;
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

    void push(int value)
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
    Stack st;
    st.push(7);
    st.top();
    st.push(5);
    st.top();
    st.pop();
    st.top();
    st.pop();
    st.pop();
    return 0;
}