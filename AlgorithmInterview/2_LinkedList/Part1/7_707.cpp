#include<bits/stdc++.h>
using namespace std;

struct PPListNode {
    int val;
    PPListNode *prev, *next;
    PPListNode(int _val) : val(_val), prev(nullptr), next(nullptr) {}
};

class MyLinkedList {
private:
    int size = 0;
    PPListNode *headPtr = nullptr;
    PPListNode *tailPtr = nullptr;

public:
    MyLinkedList() {}

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        PPListNode *p = headPtr;
        if (index > size / 2) {
            p = tailPtr;
            for (int i = 0; i < size - index - 1; ++i) p = p->prev;
        } else {
            for (int i = 0; i < index; ++i) p = p->next;
        }
        return p->val;
    }

    void addAtHead(int val) {
        PPListNode *newNode = new PPListNode(val);
        if (size == 0) {
            headPtr = tailPtr = newNode;
        } else {
            newNode->next = headPtr;
            headPtr->prev = newNode;
            headPtr = newNode;
        }
        size++;
    }

    void addAtTail(int val) {
        PPListNode *newNode = new PPListNode(val);
        if (size == 0) {
            headPtr = tailPtr = newNode;
        } else {
            tailPtr->next = newNode;
            newNode->prev = tailPtr;
            tailPtr = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }

        PPListNode *p = headPtr;
        if (index > size / 2) {
            p = tailPtr;
            for (int i = 0; i < size - index - 1; ++i) p = p->prev;
        } else {
            for (int i = 0; i < index; ++i) p = p->next;
        }

        PPListNode *newNode = new PPListNode(val);
        newNode->prev = p->prev;
        newNode->next = p;
        p->prev->next = newNode;
        p->prev = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        PPListNode *p = headPtr;
        if (index > size / 2) {
            p = tailPtr;
            for (int i = 0; i < size - index - 1; ++i) p = p->prev;
        } else {
            for (int i = 0; i < index; ++i) p = p->next;
        }

        PPListNode *prevNode = p->prev;
        PPListNode *nextNode = p->next;

        if (prevNode) {
            prevNode->next = nextNode;
        } else {
            headPtr = nextNode;
        }

        if (nextNode) {
            nextNode->prev = prevNode;
        } else {
            tailPtr = prevNode;
        }

        delete p;
        size--;

        if (size == 0) {
            headPtr = tailPtr = nullptr;
        }
    }
};