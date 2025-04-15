// 90. Subsets II
// https://leetcode.com/problems/subsets-ii
package main

import (
	"fmt"
	"sort"
)

func subsetsWithDup(nums []int) [][]int {
	var res [][]int
	var backtrack func(idx int, path []int)

	// sort the array to handle duplicate subsets
	sort.Ints(nums)

	backtrack = func(idx int, path []int) {
		// valid state
		pathCopy := make([]int, len(path))
		copy(pathCopy, path)
		res = append(res, pathCopy)

		for i := idx; i < len(nums); i++ {
			if i > idx && nums[i] == nums[i-1] {
				continue
			}
			path = append(path, nums[i]) // push
			backtrack(i+1, path)         // backtrack
			path = path[:len(path)-1]    // pop
		}
	}

	backtrack(0, []int{})
	return res
}

func main() {
	fmt.Println("90. SUBSETS-II")
	fmt.Println(subsetsWithDup([]int{1, 2, 2}))
	fmt.Println(subsetsWithDup([]int{4, 4, 4, 1, 4}))
	fmt.Println(subsetsWithDup([]int{0}))
}
