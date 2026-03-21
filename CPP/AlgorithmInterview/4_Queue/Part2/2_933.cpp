#include<bits/stdc++.h>
using namespace std;

class RecentCounter {
public:
    queue<int> internalQueue;
    RecentCounter() {
    }
    
    int ping(int t) {
        internalQueue.push(t);
        while (internalQueue.front() < t - 3000)
        {
            internalQueue.pop();
        }
        return internalQueue.size();
    }
};
