// https://leetcode.com/problems/subsets
// 78. Subsets

func subsets(nums []int) [][]int {
	var res [][]int
	var backtrack func(int, []int)

	backtrack = func(idx int, path []int) {
		// copy the current path to result
		subset := make([]int, len(path))
		copy(subset, path)
		res = append(res, subset)

		// Iterate over [idx+1..] and add each item to current path
		for i := idx; i < len(nums); i++ {
			path = append(path, nums[i]) // push
			backtrack(i+1, path)         // backtrack
			path = path[:len(path)-1]    // pop
		}
	}

	backtrack(0, []int{})
	return res
}

