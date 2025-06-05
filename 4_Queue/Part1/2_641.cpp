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
