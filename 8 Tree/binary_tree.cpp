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
    node* allNode[6];

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

    void print_tree_info()
    {
        int p = -1;
        int l = -1;
        int r = -1;

        for(auto i: allNode)
        {
            if(i->parent != NULL)
            {
                p = i->parent->id;
            }
            if(i->Left != NULL)
            {
                l = i->Left->id;
            }
            if(i->Right != NULL)
            {
                r = i->Right->id;
            }

            cout<<"Node "<<i->id<<": Parent = "<<p<<" , Left child = "<<l<<" , Right child = "<<r<<'\n';
        }
    }
};

int main()
{
    BinaryTree bt;

    bt.build_binary_tree();
    bt.print_tree_info();

    return 0;
}