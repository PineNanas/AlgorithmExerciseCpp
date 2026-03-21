#include<bits/stdc++.h>
using namespace std;

class TextEditor {
public:
    string s1;
    string s2;
    TextEditor() {
        s1 = "";
        s2 = "";
    }
    
    void addText(string text) {
        for (auto &&c : text)
        {
            s1.push_back(c);
        }
    }
    
    int deleteText(int k) {
        int x = 0;
        for (int i = 0; i < k; i++)
        {
            if (s1.empty())
            {
                return x;
            }
            s1.pop_back();
            x++;
        }
        return x;
    }
    
    string cursorLeft(int k) {
        for (int i = 0; i < k; i++)
        {
            if (s1.empty())
            {
                return "";
            }
            s2.push_back(s1.back());
            s1.pop_back();
        }
        return check();
    }
    
    string cursorRight(int k) {
        for (int i = 0; i < k; i++)
        {
            if (s2.empty())
            {
                return check();
            }
            s1.push_back(s2.back());
            s2.pop_back();
        }
        return check();
    }

    string check()
    {
        string s = "";
        int start = max(0, (int)s1.size() - 10);
        for (int i = start;i < s1.size(); i++)
        {
            s.push_back(s1[i]);
        }
        return s;
    }
};