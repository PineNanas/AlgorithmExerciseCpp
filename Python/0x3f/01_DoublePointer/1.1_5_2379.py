class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        left: int = 0
        right: int = 0
        count: int = 0
        n: int = len(blocks)
        ans: int = n + 1
        while right < n:
            if blocks[right] == 'W':
                count += 1
            if right - left + 1 == k:
                ans = min(ans, count)
                if blocks[left] == 'W':
                    count -= 1
                left += 1
            right += 1
        return ans
