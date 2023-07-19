#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int value;
    node *left;
    node *right;
};

class BST
{
    public:
    node *root;

    BST()
    {
        root = NULL;
    }

    node *CreateNewNode(int value)
    {
        node *newNode = new node;
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    void BFS()
    {
        if(root == NULL) return;

        queue<node*> q;
        q.push(root);

        while(!q.empty())
        {
            node *a = q.front();
            q.pop();
            int l =-1, r=-1;
            if(a->left != NULL){
                l = a->left->value;
                q.push(a->left);
            }
            if(a->right != NULL){
                r = a->right->value;
                q.push(a->right);
            }
            cout<<"Node value = "<<a->value<<" Left Child = "<<l<<" Right Child = "<<r<<'\n';
        }
    }

    void Insert(int value){
        node *newNode = CreateNewNode(value);

        if(root == NULL)
        {
            root = newNode;
            return;
        }

        node *current = root;
        node *previous = NULL;

        while(current != NULL)
        {
            if(newNode->value > current->value)
            {
                previous = current;
                current = current->right;
            }
            else
            {
                previous = current;
                current = current->left;
            }
        }
        if(newNode->value > previous->value)
        {
            previous->right = newNode;
        }
        else
        {
            previous->left = newNode;
        }
    }

    bool Search(int value)
    {
        node *curent = root;
        while(curent != NULL)
        {
            if(value > curent->value)
            {
                curent = curent->right;
            }
            else if(value < curent->value)
            {
                curent = curent->left;
            }
            else{
                return true;
            }
        }

        return false;
    }
};

int main()
{
    BST bst;
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);

    // bst.BFS();
    cout<<bst.Search(8)<<'\n';
    cout<<bst.Search(18)<<'\n';
    return 0;
}