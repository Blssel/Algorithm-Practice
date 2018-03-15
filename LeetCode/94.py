#!/usr/bin/env python

__author__ = 'Zhiyu Yin'

# Definition for a binary tree node.
class TreeNode(object):
  def __init__(self, x):
    self.val = x
    self.left = None
    self.right = None

class Solution(object):
  ans_tmp=[]
  def inorderTraversal(self,root):
    """
      :type root: TreeNode
      :rtype: List[int]
    """
    if root is None:
      ans=Solution.ans_tmp
      Solution.ans_tmp=[]
      return ans
    else:
      if root.left is not None:
        self.inorderTraversal(root.left)
      if root is not None:
        Solution.ans_tmp.append(root.val)
      if root.right is not None:
        self.inorderTraversal(root.right)
      ans= Solution.ans_tmp
      Solution.ans_tmp=[]
      return ans
       
if __name__=='__main__':
  root=TreeNode(5)
  print Solution().inorderTraversal(root)
