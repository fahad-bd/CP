#include <bits/stdc++.h>
using namespace std;

// last non-leaf node = (n/2)-1
// call down heapify for last non-leaf node to 0 th node
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

    //O(n)
    void build_from_array(vector<int> &a)
    {
        nodes = a;
        int n = nodes.size();
        int last_non_leaf = n/2 - 1;

        for(int i=last_non_leaf; i>=0; i--)
        {
            down_heapify(i);
        }
    }
};

//O(nlogN)
vector<int> heap_sort(vector<int>a)
{
    MaxHeap h;
    h.build_from_array(a);
    vector<int>ans;
    for(int i=0;i<a.size();i++)
    {
        ans.push_back(h.ExtractMax());
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> a = {1,2,3,4,10,9,8,7};

    vector<int>sorted_a = heap_sort(a);
    for(int i=0;i<a.size();i++) cout<<sorted_a[i]<<" ";
    cout<<'\n';
    return 0;
}