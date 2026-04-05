"""
1. Two Sum LeetCode Problem 1
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
"""   
class Solution(object):
    def twoSum(self, nums, target):
        seen = {}                     # value -> index
        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen:
                return [seen[complement], i]
            seen[num] = i
        return []                     # no solution (problem guarantees one) 
    