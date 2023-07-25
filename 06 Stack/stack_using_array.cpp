//stack with static array
#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 500;
class Stack{
    public:
    int a[MAX_SIZE];
    int stack_size;

    Stack()
    {
        stack_size=0;
    }

    //and an element in the stack O(1)
    void push(int value)
    {
        if(stack_size > MAX_SIZE)
        {
            cout<<"Stack is Full!\n";
            return;
        }
        stack_size++;
        a[stack_size - 1] = value;
    }

    //delete top most element O(1)
    void pop()
    {
        if(stack_size == 0){
            cout<<"Stack is empty!\n";
            return;
        }
        a[stack_size - 1] = 0;
        stack_size--;
    }

    //returns the top element from the stack O(1)
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