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

    void Delete(int value)
    {
        node *current = root;
        node *previous = NULL;

        while(current != NULL)
        {
            if(value > current->value)
            {
                previous = current;
                current = current->right;
            }
            else if(value < current->value)
            {
                previous = current;
                current = current->left;
            }
            else 
            {
                break;
            }
        }

        if(current == NULL)
        {
            cout<<"Value not found!"<<'\n';
            return;
        }
        //case 1: node without child
        if(current->left == NULL && current->right == NULL) 
        {
            if(previous->left != NULL && previous->left->value == current->value)
            {
                previous->left = NULL;
            }
            else{
                previous->right = NULL;
            }

            delete current;
            return;
        }

        // case 2: node has only one child
        if(current->left == NULL && current->right != NULL)
        {
            if(current->left == NULL && previous->left->value == current->value)
            {
                previous->left = current->right;
            }
            else{
                previous->right = current->right;
            }
            delete current;
            return;
        }
        if(current->left != NULL && current->right == NULL)
        {
            if(current->right == NULL && previous->left->value == current->value)
            {
                previous->left = current->left;
            }
            else{
                previous->right = current->left;
            }
            delete current;
            return;
        }

        //case 3:node has two child
        node *temp = current->right;
        while(temp->left!=NULL)
        {
            temp = temp->left;
        }
        int save_value = temp->value;
        Delete(save_value);

        current->value = save_value;
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

    cout<<bst.Search(8)<<'\n';
    cout<<bst.Search(18)<<'\n';

    bst.BFS();
    cout<<'\n';

    bst.Delete(6);
    bst.BFS();
    return 0;
}