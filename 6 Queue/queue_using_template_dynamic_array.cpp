#include<bits/stdc++.h>
using namespace std;

template<class T>
class Queue{
    public:
    T *a;
    int array_cap;
    int first_position,last_position;
    int Size;

    Queue(){
        a = new T[1];
        array_cap = 1;
        first_position = 0;
        last_position = -1;
        Size = 0;
    }

    void increase_size()
    {
        T *temp = new T[array_cap*2];
        for(int i=0;i<array_cap;i++){
            temp[i] = a[i];
        }
        swap(a,temp);
        array_cap = array_cap*2;

        delete [] temp;
    }

    void enqueue(T value){
        if(Size == array_cap){
            increase_size();
        }
        last_position++;
        a[last_position] = value;
        Size++;
    }

    void dequeue(){
        if(Size == 0){
            cout<<"Queue is empty!\n";
            return;
        }
        first_position++;
        Size--;
    }

    T front(){
        if(Size == 0){
            cout<<"Queue is empty\n";
            return -1;
        }
        return a[first_position];
    }
};

int main()
{
    Queue<int>q1;
    q1.enqueue(1);
    q1.enqueue(11);
    q1.enqueue(111);
    cout<<q1.front()<<'\n';
    q1.dequeue();
    cout<<q1.front()<<'\n';
    q1.dequeue();
    cout<<q1.front()<<'\n';
    q1.dequeue();
    cout<<q1.front()<<'\n';

    Queue<char>q2;
    q2.enqueue('F');
    q2.enqueue('A');
    cout<<q2.front()<<'\n';
    return 0;
}