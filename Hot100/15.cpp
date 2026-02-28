#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;

        auto towSum = [&] (int target, int index) -> void
        {
            unordered_set<int> hashSet;
            for (int i = index; i < n; i++)
            {
                if (hashSet.contains(-target - nums[i]))
                {
                    vector<int> curVec = {target, nums[i], -target - nums[i]};
                    ranges::sort(curVec);
                    hashSet.erase(-target - nums[i]);
                    if (!ans.contains(curVec))
                    {
                        ans.insert(curVec);
                    }
                }
                else
                {
                    hashSet.insert(nums[i]);
                }
            }
        };

        for (int i = 0; i < n - 2; i++)
        {
            towSum(nums[i], i + 1);
        }
        
        vector<vector<int>> ansV(ans.begin(), ans.end());
        return ansV;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        ranges::sort(nums);

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            if (nums[i] + nums[i + 1] + nums[i + 1] > 0)
            {
                break;
            }
            if (nums[i] + nums[n - 1] + nums[n - 2] < 0)
            {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int s = nums[i] + nums[j] + nums[k];
                if (s < 0)
                {
                    j++;
                }
                else if (s > 0)
                {
                    k--;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    do
                    {
                        j++;
                    } while ( j < k && nums[j] == nums[j - 1]);
                    do
                    {
                        k--;
                    } while (j < k && nums[k] == nums[k + 1]);
                }
            }
        }
        
        return ans;
    }
};