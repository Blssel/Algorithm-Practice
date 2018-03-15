#!/usr/bin/env python

__author__ = 'Zhiyu Yin'

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
  def inorderTraversal(self,root):
    """
      :type root: TreeNode
      :rtype: List[int]
    """
    ans=[]
    if root is None:
      return
    else:
      if root.left is not None:
        inorderTraversal(root.left)
      if root is not None:
        ans.append(root.val)
      if root.right is not None:
        inorderTraversal(root.right)
      return ans
        
