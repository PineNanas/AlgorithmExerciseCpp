#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> nameVec = split(path);
        vector<string> outVec;
        for (int i = 0; i < nameVec.size(); i++)
        {
            if (nameVec[i] == "" || nameVec[i] == ".")
            {
                continue;
            }
            else if (nameVec[i] == "..")
            {   
                if (outVec.size() == 0)
                {
                    continue;
                }
                outVec.pop_back();
            }
            else    
            {
                outVec.push_back(nameVec[i]);
            }
        }
        string out;
        for (int i = 0; i < outVec.size(); i++)
        {
            out.append("/" + outVec[i]);
        }
        if (out == "")
        {
            return "/";
        }
        return out;
    }
    vector<string> split(string s){
        vector<string> out;
        string n;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '/')
            {
                n.push_back(s[i]);
            }
            else
            {
                out.push_back(n);
                n.clear();
            }
        }
        out.push_back(n);
        return out;
    }
};

int main(){
    string s = "/../";
    Solution solution;
    cout << solution.simplifyPath(s) << endl;
    return 0;
}