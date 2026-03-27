#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) -> pair<int, vector<long long>>
        {
            if (!cur)
            {
                return {0, {}};
            }
            auto [leftIn, leftV] = dfs(cur->left);
            auto [rightIn, rightV] = dfs(cur->right);
            if (leftV.size() + rightV.size() == 0)
            {
                return {cur->val == targetSum, {cur->val}};
            }
            int curIn = leftIn + rightIn;
            vector<long long> curV(move(leftV));
            curV.reserve(curV.size() + rightV.size() + 1);
            curV.insert(curV.end(),
                        make_move_iterator(rightV.begin()),
                        make_move_iterator(rightV.end()));
            curV.push_back(0);
            for (auto &&i : curV)
            {
                i += cur->val;
                if (i == targetSum)
                {
                    curIn++;
                }
            }
            return {curIn, curV};
        };

        return dfs(root).first;
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> cnt = {{0, 1}};
        int ans = 0;

        auto dfs = [&] (this auto&& dfs, TreeNode* cur, long long sum)
        {
            if (!cur)
            {
                return;
            }
            sum += cur->val;
            ans += cnt[sum - targetSum];
            cnt[sum]++;
            dfs(cur->left, sum);
            dfs(cur->right, sum);
            cnt[sum]--;
        };

        dfs(root, 0);
        return ans;
    }
};