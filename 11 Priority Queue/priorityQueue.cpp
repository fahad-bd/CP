// Queue is a linear ds but priority queue is a non linear ds
// implement based on max heap
// push() = O(logN)
// top() = max value O(1)
// pop = delete top O(1)
// size = O(1)

#include <bits/stdc++.h>
using namespace std;

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

    //O(logN)
    void down_heapify(int index)
    {
        while(1)
        {
            int largest = index;
            int l = 2*index + 1;
            int r = 2*index + 2;

            if(l < nodes.size() && nodes[largest] < nodes[l])
            {
                largest = l;
            }
            if(r < nodes.size() && nodes[largest] < nodes[r])
            {
                largest = r;
            }
            if(largest == index)
            {
                break;
            }
            swap(nodes[index], nodes[largest]);
            index = largest;
        }
    }

    //O(logN)
    void Delete(int index)
    {
        if(index >= nodes.size()) return;
        swap(nodes[index], nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(index);
    }

    //O(1)
    int getMax()
    {
        if(nodes.empty())
        {
            cout<<"Heap is empty!";
            return -1;
        }
        return nodes[0];
    }

    //return max and delet that
    //O(logN)
    int ExtractMax()
    {
        if(nodes.empty())
        {
            cout<<"Heap is empty!";
            return -1;
        }
        int result = nodes[0];
        Delete(0);
        return result;
    }

    int getSize()
    {
        return nodes.size();
    }
};

class PriorityQueue{
    public:
    MaxHeap h;
    PriorityQueue()
    {

    }

    void Push(int x)
    {
        h.Insert(x);
    }

    void Pop()
    {
        h.Delete(0);
    }

    int Top()
    {
        return h.getMax();
    }

    int Size()
    {
        return h.getSize();
    }
};

int main() {
    PriorityQueue pq;
    pq.Push(1);
    pq.Push(2);
    pq.Push(3);
    pq.Push(4);
    pq.Push(7);
    pq.Push(8);
    pq.Push(10);
    cout<<pq.Top()<<'\n';
    pq.Pop();
    while(pq.Size())
    {
        cout<<pq.Top()<<" ";
        pq.Pop();
    }
    cout<<'\n';
    return 0;
}