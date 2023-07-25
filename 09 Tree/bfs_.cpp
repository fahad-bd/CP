#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int id;
    node *Left;
    node *Right;
    node *parent;
};

class BinaryTree{
    public:
    node *root;

    BinaryTree()
    {
        root = NULL;
    }

    node *CreateNewNode(int value){
        node *newNode = new node;
        newNode->id = value;
        newNode->Right = NULL;
        newNode->Left = NULL;
        newNode->parent = NULL;

        return newNode;
    }

    void build_binary_tree()
    {
        node* allNode[6];
        for(int i=0;i<6;i++)
        {
            allNode[i] = CreateNewNode(i);
        }

        allNode[0]->Left = allNode[1];
        allNode[0]->Right = allNode[2];

        allNode[1]->Left = allNode[5];
        allNode[1]->parent = allNode[0];

        allNode[2]->Left = allNode[3];
        allNode[2]->Right = allNode[4];
        allNode[2]->parent = allNode[0];

        allNode[3]->parent = allNode[2];
        allNode[4]->parent = allNode[2];
        allNode[5]->parent = allNode[1];

        root = allNode[0];
    }

    void BFS()
    {
        if(root == NULL) return;
        
        queue<node*>q;
        q.push(root);

        while(!q.empty())
        {
            node* a = q.front();
            q.pop();
            int p = -1, l = -1, r = -1;
            if(a->Left != NULL)
            {
                l = a->Left->id;
                q.push(a->Left);
            }
            if(a->Right != NULL)
            {
                r = a->Right->id;
                q.push(a->Right);
            }
            if(a->parent != NULL)
            {
                p = a->parent->id;
            }
            cout<<"Node id = "<<a->id<<" Left Child = "<<l;
            cout<<" Right Child = "<<r<<" Parent Id = "<<p<<'\n';
        }
    }
};

int main()
{
    BinaryTree bt;

    bt.build_binary_tree();
    bt.BFS();

    return 0;
}