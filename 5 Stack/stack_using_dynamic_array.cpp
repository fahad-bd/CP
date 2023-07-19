//stack with dynamic array
#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int *a;
    int stack_size;
    int capacity;

    Stack()
    {
        a = new int[1];
        capacity = 1;
        stack_size=0;
    }

    //makes the array capacity multiplied by 2
    void increase_size()
    {
        int *temp;
        temp = new int[capacity * 2];
        for(int i=0; i<capacity; i++){
            temp[i] = a[i];
        }
        swap(a,temp);
        delete []temp; //this is the syntex for delete a array
        capacity = capacity * 2;
    }

    //and an element in the stack O(1)
    void push(int value)
    {
        if(stack_size > capacity)
        {
            increase_size();
        }
        stack_size++;
        a[stack_size - 1] = value;
    }

    //delete top most element
    void pop()
    {
        if(stack_size == 0){
            cout<<"Stack is empty!\n";
            return;
        }
        a[stack_size - 1] = 0;
        stack_size--;
    }

    //returns the top element from the stack
    void top()
    {
        if(stack_size == 0){
            cout<<"Stack is empty!\n";
            return;
        }
        cout<<a[stack_size - 1]<<'\n';
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