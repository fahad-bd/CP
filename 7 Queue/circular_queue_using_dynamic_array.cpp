#include<bits/stdc++.h>
using namespace std;

// Circular Queue using dynamic array

class Queue{
    public:
    int *a;
    int array_cap;
    int l,r;
    int sz;

    Queue(){
        a = new int[1];
        array_cap = 1;
        l = 0;
        r = -1;
        sz = 0;
    }

    void remove_circular()
    {
        if(l > r){
            int *temp = new int[array_cap];
            int index = 0;
            for(int i=l; i<array_cap;i++){
                temp[index] = a[i];
                index++;
            }
            for(int i=0;i<=r;i++){
                temp[index] = a[i];
                index++;
            }
            swap(temp,a);
            l = 0 ;
            r = array_cap - 1;

            delete [] temp;
        }
    }

    void increase_size()
    {
        remove_circular();
        int *temp = new int[array_cap*2];
        for(int i=0;i<array_cap;i++){
            temp[i] = a[i];
        }
        swap(a,temp);
        array_cap = array_cap*2;

        delete [] temp;
    }

    // O(1)
    void enqueue(int value){
        if(sz == array_cap){
            increase_size();
        }

        r++;
        if(r == array_cap)
        {
            r = 0;
        }
        a[r] = value;
        sz++;
    }

    // O(1)
    void dequeue(){
        if(sz == 0){
            cout<<"Queue is empty!\n";
            return;
        }
        l++;
        if(l == array_cap)
        {
            l = 0;
        }
        sz--;
    }

    // O(1)
    int front(){
        if(sz == 0){
            cout<<"Queue is empty\n";
            return -1;
        }
        return a[l];
    }

    // O(1)
    int Size(){
        return sz;
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