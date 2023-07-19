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

    node *CreateNewNode(int id){
        node *newNode = new node;
        newNode->id = id;
        newNode->Right = NULL;
        newNode->Left = NULL;
        newNode->parent = NULL;

        return newNode;
    }

    void Insertion(int id)
    {
        node *newNode = CreateNewNode(id);
        if(root == NULL)
        {
            root = newNode;
            return;
        }

        queue<node*>q;
        q.push(root);

        while(!q.empty())
        {
            node* a = q.front();
            q.pop();
            if(a->Left != NULL)
            {
                q.push(a->Left);
            }
            else{
                a->Left = newNode;
                newNode->parent = a;
                
                return;
            }
            if(a->Right != NULL)
            {
                q.push(a->Right);
            }
            else
            {
                a->Right = newNode;
                newNode->parent = a;

                return;
            }
        }
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

    void DFS(node *a)
    {
        if(a == NULL)
        {
            return;
        }
        cout<<a->id<<" ";
        DFS(a->Left);
        DFS(a->Right);
    }
};

int main()
{
    BinaryTree bt;

    bt.Insertion(0);
    bt.Insertion(1);
    bt.Insertion(2);
    bt.Insertion(3);
    bt.BFS();

    return 0;
}