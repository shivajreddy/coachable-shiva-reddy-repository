<<<<<<< HEAD
package main

func subsetXORSum(nums []int) int {
=======
// 1863. Sum of All Subset XOR Totals
// https://leetcode.com/problems/sum-of-all-subset-xor-totals

func subsetXORSum(nums []int) int {
	// Helper function to get XOR total of a given array of nums
	var xor_total func([]int) int
	xor_total = func(path []int) int {
		res := 0
		for _, num := range path {
			res ^= num
		}
		return res
	}

	res := 0

	var backtrack func(idx int, path []int)
	backtrack = func(idx int, path []int) {
		res += xor_total(path)

		for idx := idx; idx < len(nums); idx++ {
			path = append(path, nums[idx]) // push
			backtrack(idx+1, path)         // backtrack
			path = path[:len(path)-1]      // pop
		}
	}

	backtrack(0, []int{})
	return res
>>>>>>> refs/remotes/origin/benchmark_4
}
