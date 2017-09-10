#!/usr/bim/env python3
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


# 动态规划实现
def gen_BSTs(n):
    if n == 0:
        return 1, []
    nums = [1 for i in range(n+1)]
    '''
    BSTMatrix整体是一个(n+1)*(n+1)的二维矩阵，
    其中每个元素是一个存放了多个BST树的列表
    '''
    BSTMatrix = [[[None] for i in range(n+1)] for i in range(n+1)]
    '''
    从右下角[n][n]位置开始，每一行按照从左向右顺序，
    逆序填充BSTsMatrix，同时保证b <= e
    '''
    for b in range(n, 0, -1):   # b: n~1
        print('b: %d' % b)
        for e in range(b, n+1): # e: b~n
            print('\te: %d' % e)
            # 对角线位置，该列表只有一个BST树，
            # 而该BST树只有一个元素
            if b == e:
                BSTMatrix[b][e] = [TreeNode(b)]
            else:
                # 对于BSTMatrix中无用的位置，比如[0][i], i: 0~n，
                # 将该位置的列表填充为None，对于有用的位置，需要
                # 先将列表清空，为后续填充元素做准备
                BSTMatrix[b][e] = []
                print('length: %d' % (e - b + 1))
                for i in range(b, e+1): # i: b~e
                    print('\t\ti: %d' % i)
                    leftList = BSTMatrix[b][i-1]
                    # 防止 i+1 发生越界
                    if n < i + 1:
                        rightList = [None]
                    else:
                        rightList= BSTMatrix[i+1][e]
                    '''
                    对于leftList和rightList中的BST树进行排列组合
                    '''
                    for k in range(len(leftList)):
                        for l in range(len(rightList)):
                            # 根节点
                            BST = TreeNode(i)
                            # 插入左子树
                            BST.left = leftList[k]
                            # 插入右子树
                            BST.right = rightList[l]
                            # 将BST加入到BSTMatrix[b][e]中
                            BSTMatrix[b][e].append(BST)

    for i in range(2, n+1):
        cnt = 0
        for j in range(1, i+1):
            cnt += nums[j-1]*nums[1]*nums[i-j]
        nums[i] = cnt
    print('nums:\n%s' % nums)
    print('BSTMatrix:')
    for b in range(1, n+1):
        print('[', end='')
        for e in range(b, n+1):
            for i in range(len(BSTMatrix[b][e])):
                traveLevel(BSTMatrix[b][e][i])
                print(', ', end='')
            print(';\t', end='')
        print(']')

    return nums[n], BSTMatrix[1][n]
 

# 朴素的分治法递归实现
def gen_BSTs_R(n):
    BSTList = []
    if n == 0:
        BSTList = []
    else:
        BSTList = gen_BSTs_R_sub(1, n)
    return BSTList

def gen_BSTs_R_sub(b, e):
    BSTList = []
    if e < b:
        BSTList = [None]
        return BSTList
    for i in range(b, e+1): # i: b~e
        leftList = gen_BSTs_R_sub(b, i-1)
        rightList = gen_BSTs_R_sub(i+1, e)
        for k in range(len(leftList)):
            for l in range(len(rightList)):
                # 根节点
                BST = TreeNode(i)
                # 左子树
                BST.left = leftList[k]
                # 右子树
                BST.right = rightList[l]
                # 将BST加入到BSTList列表中
                BSTList.append(BST)
    return BSTList

def printBSTList(BSTList):
    for BST in BSTList:
        traveLevel(BST)
        print('; ', end='')
    print('\n')

