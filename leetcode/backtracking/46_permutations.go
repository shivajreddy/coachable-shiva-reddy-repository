// 46. Permutations
// https://leetcode.com/problems/permutations

func permute(nums []int) [][]int {
	var res [][]int
	used := make([]bool, len(nums))
	var backtrack func(path []int)

	backtrack = func(path []int) {
		// valid state
		if len(path) == len(nums) {
			pathCopy := make([]int, len(nums))
			copy(pathCopy, path)
			res = append(res, pathCopy)
			return
		}

		for i := range nums {
			if used[i] {
				continue
			}
			used[i] = true
			path = append(path, nums[i]) // push
			backtrack(path)              // backtrack

			path = path[:len(path)-1] // pop
			used[i] = false
		}
	}

	backtrack([]int{})
	return res
}
