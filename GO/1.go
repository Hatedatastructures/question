package main

// 题目：两数之和
// https://leetcode.cn/problems/two-sum/description/?envType=problem-list-v2&envId=hash-table

func twoSum(nums []int, target int) []int {
	hash := map[int]int{}
	for index, num := range nums {
		if p, ok := hash[target-num]; ok {
			return []int{p, index}
		}
		hash[num] = index
	}
	return nil
}
