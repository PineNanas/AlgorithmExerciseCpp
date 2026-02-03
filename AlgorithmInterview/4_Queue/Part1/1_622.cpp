#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    vector<int> internalVec;
    int front;
    int rear;
    int size;
    int count;
    MyCircularQueue(int k) {
        internalVec.resize(k);
        size = k;
        front = 0;
        rear = k - 1;
        count = 0;
    }
    
    bool enQueue(int value) {
        if (isFull())
        {
            return false;
        }
        else
        {
            rear = (rear + 1) % size;
            internalVec[rear] = value;
            count++;
            return true;
        }
    }
    
    bool deQueue() {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            front = (front + 1) % size;
            count--;
            return true;
        }
    }
    
    int Front() {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return internalVec[front];
        }
    }
    
    int Rear() {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return internalVec[rear];
        }
        
    }
    bool isEmpty() {
        if (count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    bool isFull() {
        if (count == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
