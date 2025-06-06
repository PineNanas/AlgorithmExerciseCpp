#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    vector<int> internalVec;
    int front;
    int rear;
    int size;
    int count;
    MyCircularDeque(int k) {
        internalVec.resize(k);
        size = k;
        front = 0;
        rear = k - 1;
        count = 0;  
    }
    
    bool insertFront(int value) {
        if (isFull())
        {
            return false;
        }
        else
        {
            front = (front + size - 1) % size;
            internalVec[front] = value;
            count++;
            return true;
        }
    }
    
    bool insertLast(int value) {
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
    
    bool deleteFront() {
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
    
    bool deleteLast() {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            rear = (rear + size - 1) % size;
            count--;
            return true;
        }
    }
    
    int getFront() {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return internalVec[front];
        }
    }
    
    int getRear() {
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

class FrontMiddleBackQueue {
public:
    MyCircularDeque dequeFront {1000};
    MyCircularDeque dequeRear  {1000};
    FrontMiddleBackQueue() {;
    }
    
    void pushFront(int val) {
        dequeFront.insertFront(val);
        if (dequeFront.count > dequeRear.count)
        {
            dequeRear.insertFront(dequeFront.getRear());
            dequeFront.deleteLast();
        }
    }
    
    void pushMiddle(int val) {
        if (dequeFront.count < dequeRear.count)
        {
            dequeFront.insertLast(val);
        }
        else
        {
            dequeRear.insertFront(val);
        }
    }
    
    void pushBack(int val) {
        dequeRear.insertLast(val);
        if (dequeRear.count > dequeFront.count + 1)
        {
            dequeFront.insertLast(dequeRear.getFront());
            dequeRear.deleteFront();
        }
    }
    
    int popFront() {
        if (dequeFront.count + dequeRear.count == 0)
        {
            return -1;
        }
        if (dequeFront.count < dequeRear.count)
        {
            dequeFront.insertLast(dequeRear.getFront());
            dequeRear.deleteFront();
        }
        int ans = dequeFront.getFront();
        dequeFront.deleteFront();
        return ans;
    }
    
    int popMiddle() {
        if (dequeFront.count + dequeRear.count == 0)
        {
            return -1;
        }
        int ans;
        if (dequeFront.count < dequeRear.count)
        {
            ans = dequeRear.getFront();
            dequeRear.deleteFront();
        }
        else
        {
            ans = dequeFront.getRear();
            dequeFront.deleteLast();
        }
        return ans;
    }
    
    int popBack() {
        if (dequeFront.count + dequeRear.count == 0)
        {
            return -1;
        }
        
        if (dequeRear.count <= dequeFront.count)
        {
            dequeRear.insertFront(dequeFront.getRear());
            dequeFront.deleteLast();
        }
        int ans = dequeRear.getRear();
        dequeRear.deleteLast();
        return ans;
    }
};