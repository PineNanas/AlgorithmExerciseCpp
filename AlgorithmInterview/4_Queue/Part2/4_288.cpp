#include<bits/stdc++.h>
using namespace std;

class ZigzagIterator {
public:
    vector<vector<int>> vectors;
    vector<int> pointers;
    int vectorSize;
    int now;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vectors.push_back(v1);
        pointers.push_back(0);
        vectors.push_back(v2);
        pointers.push_back(0);
        vectorSize = 2;
        now = 0;
    }

    int next() {
        while (isEnded(now))
        {
            now = (now + 1) % vectorSize;
        }
        int ans = vectors[now][pointers[now]];
        pointers[now]++;
        now = (now + 1) % vectorSize;
        return ans;
    }

    bool hasNext() {
        bool hasNext = false;
        for (int i = 0; i < vectors.size(); i++)
        {
            if (!isEnded(i))
            {
                hasNext = true;
            }
        }
        return hasNext;
    }

    bool isEnded(int k)
    {
        if (pointers[k] < vectors[k].size())
        {
            return false;
        }
        return true;
    }
};
