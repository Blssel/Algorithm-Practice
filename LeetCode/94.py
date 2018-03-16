
__author__ = 'Zhiyu Yin'

# Definition for a binary tree node.
class TreeNode(object):
  def __init__(self, x):
    self.val = x
    self.left = None
    self.right = None

class Solution(object):
  def inorderTraversal(self,root):
    """
      :type root: TreeNode
      :rtype: List[int]
    """
    ans=[]
    self.recursive_traversal(root,ans)
    return ans

  def recursive_traversal(self, root, ans):
    if root is None:
      return ans
    else:
      if root.left is not None:
	self.recursive_traversal(root.left, ans)
      if root is not None:
        ans.append(root.val)
      if root.right is not None:
        self.recursive_traversal(root.right, ans)
       
if __name__=='__main__':
  root=TreeNode(5)
  print Solution().inorderTraversal(root)
