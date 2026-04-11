from queue import PriorityQueue
import random

class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        pq: PriorityQueue[int] = PriorityQueue()
        for num in nums:
            pq.put((-num, num))
        for _ in range(k - 1):
            pq.get()
        return pq.get()[1]

class Solution2:
    def partition(self, nums: list[int], left: int, right: int) -> int:
        i: int = random.randint(left, right)
        pivot: int = nums[i]
        nums[i], nums[left] = nums[left], nums[i]
        i, j = left + 1, right
        while True:
            while i <= j and nums[i] < pivot:
                i += 1
            while i <= j and nums[j] > pivot:
                j -= 1
            if i >= j:
                break
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
        nums[left], nums[j] = nums[j], nums[left]
        return j

    def findKthLargest(self, nums: list[int], k: int) -> int:
        n: int = len(nums)
        left, right = 0, n - 1
        while True:
            pivot: int = self.partition(nums, left, right)
            if pivot == n - k:
                return nums[pivot]
            elif pivot < n - k:
                left = pivot + 1
            else:
                right = pivot - 1
