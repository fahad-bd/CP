#include<bits/stdc++.h>
using namespace std;

//space complexity of class O(n)
class Array{
    private:
    int *arr;
    int cap;
    int size;
    void increase_size() //
    {
        cap = cap * 2;
        int *tmp = new int[cap];
        for(int i=0;i<size;i++){
            tmp[i] = arr[i];
        }
        delete [] arr;
        arr = tmp;
    }

    public:
    Array()
    {
        arr = new int[1];
        cap = 1;
        size = 0;
    }
    void Push_back(int x){ //O(NlonN)
        if(cap==size) increase_size();
        arr[size] = x;
        size++;
    }
    void Print() //O(N)
    {
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    int getSize()//O(1)
    {
        return size;
    }
    int getElement(int idx){//O(1)
        if(idx>=size){
            cout<<"Error "<<idx<<"is out of bound!\n";
            return -1;
        }
        return arr[idx];
    }

    void Insert(int pos, int x){ //O(n)
        if(cap==size) increase_size();
        for(int i=size-1; i>=pos; i--){
            arr[i+1] = arr[i];
        }
        arr[pos] = x;
        size++;
    }

    void Pop_back(){
        if(size==0){
            cout<<"Current size is 0\n";
            return ;
        }
        size--;
    }

    void Erase(int pos){
        if(pos >= size){
            cout<<"Position doesn't exist.\n";
            return;
        }
        for(int i=pos+1; i<size; i++){
            // arr[i-1] = arr[i];
            swap(arr[i-1],arr[i]);
        }
        size--;
    }
};

int main()
{
    Array a;
    a.Push_back(10);
    a.Push_back(20);
    a.Push_back(30);
    a.Print();
    cout<<'\n';
    cout<<a.getSize()<<'\n';
    for(int i=0;i<a.getSize();i++){
        cout<<a.getElement(i)<<" ";
    }
    cout<<'\n';
    a.Insert(1,1);
    a.Print();
    cout<<'\n';
    a.Pop_back();
    a.Print();
    cout<<'\n';
    a.Erase(1);
    a.Print();
    return 0;
}