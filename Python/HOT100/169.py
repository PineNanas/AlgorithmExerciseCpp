class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        count: int = 0
        ans: int = 0
        for num in nums:
            if count == 0:
                ans = num
            count += 1 if num == ans else -1
        return ans
