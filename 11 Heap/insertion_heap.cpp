//heap is a complete binary tree
#include <bits/stdc++.h>
using namespace std;
// for i index left child (2i+1) right chiil (2i+2) 
// parent (i-1)/2

class MaxHeap{
    public:
    vector<int>nodes;

    MaxHeap(){

    }

    //O(logN)
    void up_heapify(int index)
    {
        while(index > 0 && nodes[index] > nodes[(index-1)/2])
        {
            swap(nodes[index], nodes[(index-1)/2]);
            index = (index-1)/2;
        }
    }

    //O(logN)
    void Insert(int value)
    {
        nodes.push_back(value);
        up_heapify(nodes.size()-1);
    }

    //O(n)
    void PrintHeap()
    {
        for(int i=0;i<nodes.size();i++)
        {
            cout<<nodes[i]<<" ";
        }
        cout<<'\n';
    }
};

int main() {
    MaxHeap mh;
    mh.Insert(2);
    mh.Insert(4);
    mh.Insert(1);
    mh.Insert(5);
    mh.PrintHeap();
    return 0;
}