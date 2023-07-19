#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 500;

class Queue{
    public:
    int a[MAX_SIZE];
    int l,r;

    Queue(){
        l = 0;
        r = -1;
    }

    // O(1)
    void enqueue(int value){
        if(r+1 > MAX_SIZE){
            cout<<"Queue is full\n";
            return;
        }
        r++;
        a[r] = value;
    }

    // O(1)
    void dequeue(){
        if(l > r){
            cout<<"Queue is empty!\n";
            return;
        }
        l++;
    }

    // O(1)
    int front(){
        if(l > r){
            cout<<"Queue is empty\n";
            return -1;
        }
        return a[l];
    }

    // O(1)
    int Size(){
        return r-l+1;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<q.Size()<<endl;

    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;

    cout<<q.Size()<<endl;
    return 0;
}