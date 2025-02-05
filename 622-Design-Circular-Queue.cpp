class MyCircularQueue 
{
    vector<int> queue;
    int front; //used for removing or dequeue
    int rear; //used for enqueue or adding 
    int n;

    //elements will be added from left to right same as the normal array
public:
    MyCircularQueue(int k) 
    {
        n = k;
        queue.resize(n);
        front = rear = -1; //because queue is empty right now
    }
    
    bool enQueue(int value) 
    {
        if((rear + 1) % n == front)
        {
            return false; //overflow
        }

        //if empty
        if(rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % n; //the mod to increment
        }

        queue[rear] = value;

        return true;
    }
    
    bool deQueue() 
    {
        if(front == -1) return false; //queue is empty

        if(front == rear)
        {
            front = rear = -1; //the front equal rear only on the empty of array
        }
        else
        {
            front = (front + 1) % n; //the mod to increment
        }

        return true;
    }
    
    int Front() 
    {
        if(front == -1) return -1;

        return queue[front];
    }
    
    int Rear() 
    {
        if(rear == -1) return -1;
        return queue[rear];
    }
    
    bool isEmpty() 
    {
        return front == -1;
    }
    
    bool isFull() 
    {
        return (rear + 1) % n == front; //checking if complete
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