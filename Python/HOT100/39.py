class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        candidates.sort()
        res: list[list[int]] = []
        path: list[int] = []

        def backtracking(start: int, target: int) -> None:
            if target == 0:
                res.append(path[:])
                return
            for i in range(start, len(candidates)):
                if candidates[i] > target:
                    break
                path.append(candidates[i])
                backtracking(i, target - candidates[i])
                path.pop()
        backtracking(0, target)
        return res
