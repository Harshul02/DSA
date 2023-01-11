#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int val;
    struct Node *left;
    struct Node *right;
}TreeNode;

TreeNode* newNode(int data)
{
    TreeNode* temp = new TreeNode;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

vector<int> getinorder(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *cur = root;

    while(cur != NULL)
    {
        if(cur->left == NULL)
        {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode *prev = cur->left;

            while(prev->right && prev->right != cur)
            {
                prev = prev->right;
            }
            if(prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}


int main()
{
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(6);

    vector<int> v;

    v = getinorder(root);

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}