from functools import cache

class Solution:
    def jump(self, nums: list[int]) -> int:
        if len(nums) <= 1:
            return 0
        @cache
        def dfs(i: int) -> int:
            if nums[i] >= len(nums) - 1 - i:
                return 1
            if nums[i] == 0:
                return 100000
            return min(dfs(i + j) for j in range(1, nums[i] + 1)) + 1
        return dfs(0)

class Solution2:
    def jump(self, nums: list[int]) -> int:
        step: int = 0
        n: int = len(nums)
        cur: int = 0
        far: int = 0
        for i in range(n - 1):
            far = max(far, i + nums[i])
            if i == cur:
                step += 1
                cur = far
        return step
