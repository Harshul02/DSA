#include <iostream>
#include <queue>
using namespace std;

typedef struct Node{
    int data;
    Node* lchild;
    Node* rchild;
}Node;

void preorder(Node *root)
{
    cout<<root->data;
    preorder(root->lchild);
    preorder(root->rchild);
}

void create()
{
    Node *p, *t;
    int x;
    queue<Node*> q;
    cout<<"Enter the root value: ";
    cin>>x;
    Node* root= new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.push(root);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cout<<"Enter the left child: ";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.push(t);
        }
        cout<<"Enter the right child: ";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.push(t);
        }
    }
    preorder(root);
}

int main()
{
    create();
    return 0;
}
