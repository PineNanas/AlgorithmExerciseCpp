class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if root is None:
            return None
        if root is p or root is q:
            return root
        left: TreeNode = self.lowestCommonAncestor(root.left, p, q)
        right: TreeNode = self.lowestCommonAncestor(root.right, p, q)
        if left and right:
            return root
        return left if left else right
