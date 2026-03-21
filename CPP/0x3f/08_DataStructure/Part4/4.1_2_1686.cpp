#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        ranges::sort(deck);
        queue<int> deckQ;
        for (int i = 0; i < n; i++)
        {
            deckQ.push(i);
        }
        vector<int> index;
        while (!deckQ.empty())
        {
            index.push_back(deckQ.front());
            deckQ.pop();
            if (!deckQ.empty())
            {
                deckQ.push(deckQ.front());
                deckQ.pop();
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[index[i]] = deck[i];
        }
        return ans;
    }
};