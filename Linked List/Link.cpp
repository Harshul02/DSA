#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void display(Node* left)
{
    while(left!=NULL)
    {
        cout<<left->data<<" ";
        left=left->next;
    }
}

int main()
{
    Node *n, *left;
    int ch;
    do{
        int num;
        cout<<"Enter the data: ";
        cin>>num;
        n= new Node();
        if(n!=NULL)
        {
            n->data=num;
            if(left==NULL)
            {
                left=n;
                left->next=NULL;
            }
            else{
                n->next=left;
                left=n;
            }
        }
        cout<<"Do you want to continue: ";
        cin>>ch;
    }while(ch!=0);
    display(left);
    return 0;
}