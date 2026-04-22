class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        ans: int = 0
        for num in nums:
            ans ^= num
        return ans
