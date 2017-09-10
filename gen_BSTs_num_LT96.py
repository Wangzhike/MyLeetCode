#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def traveLevel(node):
    nodes = []
    if node != None:
        nodes = [node]
    i = 0
    while i < len(nodes):
        node = nodes[i]
        print(node.val, end=' ')
        i += 1
        if node.left != None:
            nodes.append(node.left)
        if node.right != None:
            nodes.append(node.right)


class TreeNode(object):

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# 朴素的分治法递归实现
def gen_BSTs_num(n):
    if n <= 1:
        return 1
    cnt = 0
    for i in range(1, n+1): # i: 1~n
        cnt += gen_BSTs_num(i-1)*1*gen_BSTs_num(n-i)
    return cnt


# 自顶向下的动态规划实现
def gen_BSTs_num_topDown(n):
    nums = [None for i in range(n+1)]
    return gen_BSTs_num_topDown_dp(nums, n)

def gen_BSTs_num_topDown_dp(nums, n):
    if nums[n] != None:
        return nums[n]
    if n <= 1:
        num = 1
    else:
        num = 0
        for i in range(1, n+1): # i: 1~n
            num += gen_BSTs_num_topDown_dp(nums, i-1)*1*\
                    gen_BSTs_num_topDown_dp(nums, n-i)
    nums[n] = num
    return nums[n]


# 自底向上的动态规划实现
def gen_BSTs_num_bottomUp(n):
    nums = [1 for i in range(n+1)]
    for i in range(2, n+1): # i: 2~n
        num = 0
        for j in range(1, i+1): # j: 1~i
            num += nums[j-1]*nums[i-j]
        nums[i] = num
    return nums[n]

