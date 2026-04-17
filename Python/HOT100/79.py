from collections import Counter

class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        cnt = Counter(c for row in board for c in row)
        if any(cnt[c] < word.count(c) for c in set(word)):
            return False
        if cnt[word[0]] > cnt[word[-1]]:
            word = word[::-1]

        m: int = len(board)
        n: int = len(board[0])

        def dfs(i: int, j: int, k: int) -> bool:
            if board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True
            board[i][j] = '#'
            for x, y in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                if 0 <= x < m and 0 <= y < n and dfs(x, y, k + 1):
                    return True
            board[i][j] = word[k]
            return False

        return any(dfs(i, j, 0) for i in range(m) for j in range(n))
