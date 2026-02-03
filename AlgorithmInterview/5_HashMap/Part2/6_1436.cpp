#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> starts;
        for (int i = 0; i < paths.size(); i++)
        {
            starts.insert(paths[i][0]);
        }
        for (int i = 0; i < paths.size(); i++)
        {
            if (!starts.count(paths[i][1]))
            {
                return paths[i][1];
            }
        }
        return "asdfasdf";
    }
};