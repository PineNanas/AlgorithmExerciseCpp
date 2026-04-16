class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        res: list[str] = []

        def backtracking(left: int, right: int, path: str) -> None:
            if left == n and right == n:
                res.append(path)
                return
            if left < n:
                backtracking(left + 1, right, path + '(')
            if right < left:
                backtracking(left, right + 1, path + ')')
            return
        backtracking(0, 0, '')
        return res
