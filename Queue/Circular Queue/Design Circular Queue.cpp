class MyCircularQueue {
public:

    int *p;
    int f = -1;
    int r = -1;
    int size;
    MyCircularQueue(int k) {
        p = (int *)malloc(k * sizeof(int));
        size = k;
    }
    
    bool enQueue(int value) {
        if(f==-1 and r == -1)
        {
            f = r = 0;
            p[r] = value;
            return true;
        }
        else if((r+1)%size == f)
            return false;
        else{
        r = (r+1)%size;
        p[r] = value;
        }
        return true;
    }
    
    bool deQueue() {
        if(f == -1 and r == -1)
            return false;
        else if(f == r)
        {
            f = r = -1;
            return true;
        }
        else{
        f = (f+1)%size;
        }
        return true;
    }
    
    int Front() {
        if(f == -1)
            return -1;
        return p[f];
    }
    
    int Rear() {
        if(r == -1)
            return -1;
        return p[r];
    }
    
    bool isEmpty() {
        if(f == -1 and r == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((r+1)%size == f)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */