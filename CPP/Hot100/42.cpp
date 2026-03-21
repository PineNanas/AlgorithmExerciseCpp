#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> minStk;
        stack<int> moveStk;
        int ans = 0;
        for (auto &&n : height)
        {
            if (minStk.empty() || n <= minStk.top())
            {
                minStk.push(n);
            }
            else
            {
                while (!minStk.empty() && minStk.top() < n)
                {
                    moveStk.push(minStk.top());
                    minStk.pop();
                }
                int threshold;
                if (minStk.empty())
                {
                    threshold = moveStk.top();  
                    moveStk.pop();
                    while (!moveStk.empty())
                    {
                        ans += threshold - moveStk.top();
                        moveStk.pop();
                    }
                }
                else
                {
                    threshold = n;
                    while (!moveStk.empty())
                    {
                        ans += threshold - moveStk.top();
                        moveStk.pop();
                        minStk.push(n);
                    }
                }
                minStk.push(n);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> minStk;
        int ans = 0;
        for (int i = 0; i < height.size(); i++)
        {
            int n = height[i];
            while (!minStk.empty() && n > height[minStk.top()])
            {
                int bottomH = height[minStk.top()];
                minStk.pop();
                if (minStk.empty())
                {
                    break;
                }
                ans += (i - minStk.top() - 1) * (min(height[minStk.top()], n) - bottomH);
            }
            minStk.push(i);
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> premax(n, height[0]);
        vector<int> sufmax(n, height[n - 1]);
        for (int i = 1; i < n; i++)
        {
            premax[i] = max(premax[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            sufmax[i] = max(sufmax[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int h = min(premax[i], sufmax[i]) - height[i];
            ans += h;
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int ans = 0;
        int leftMax = 0;
        int rightMax = 0;
        while (left <= right)
        {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (leftMax < rightMax)
            {
                ans += leftMax - height[left];
                left++;
            }
            else
            {
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};