#!/usr/bin/env python

__author__ = 'Zhiyu Yin'

# Definition for a binary tree node.
# class TreeNode(object):
#   def __init__(self, x):
#     self.val = x
#     self.left = None
#     self.right = None

class Solution(object):
  def inorderTraversal(self,root):
    """
      :type root: TreeNode
      :rtype: List[int]
    """
    ans=[]
    self.recursive_traversal(root,ans)
    return ans

  def recusive_traversal(root,ans)
    if root is None:
      return ans
    else:
      if root.left is not None:
	recursive_traversal(root.left)
      if root is not None:
        ans.append(root.val)
      if root.right is not None:
        recursive_traversal(root.right)
       
if __name__=='__main__':
  root=TreeNode(5)
  print Solution().inorderTraversal(root)
