#include<iostream>
using namespace std;

typedef struct queue{
    int size;
    int front;
    int rear;
    int *Q;
}queuetype;

void enqueue(queuetype *q, int x)
{
    if(q->rear == q->size-1)
        cout<<"Queue is full"<<endl;
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(queuetype *q)
{
    int x=-1;
    if(q->front == q->rear)
        cout<<"queue is empty"<<endl;
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

void create(queuetype *q, int size)
{
    q->front=q->rear=-1;
    q->Q = new int[size];
}

void display(queuetype q)
{

    for(int i=q.front+1; i<=q.rear; i++)
    {
        cout<<q.Q[i]<<" ";
    }
}

int main()
{
    queuetype q;
    cout<<"Enter the size: ";
    cin>>q.size;
    create(&q,q.size);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    display(q);
    cout<<endl;
    cout<<dequeue(&q);
    cout<<endl;
    display(q);
    return 0;
}
