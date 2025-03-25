// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition
// 1498. Number of subsequences

package main

import (
	"sort"
)

func numSubseq(nums []int, target int) int {
	// Sort the array first
	sort.Ints(nums)

	// Initialize result and modulo constant
	res := 0
	mod := 1000000007

	// Precompute powers of 2 to avoid repeated calculations
	n := len(nums)
	powers := make([]int, n)
	powers[0] = 1
	for i := 1; i < n; i++ {
		powers[i] = (powers[i-1] * 2) % mod
	}

	// Two-pointer approach
	left, right := 0, n-1

	for left <= right {
		if nums[left]+nums[right] <= target {
			// Number of subsequences with this min and max
			res = (res + powers[right-left]) % mod
			left++
		} else {
			right--
		}
	}

	return res
}
