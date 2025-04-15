// 39. Combination Sum
// https://leetcode.com/problems/combination-sum

func combinationSum(candidates []int, target int) [][]int {
	n := len(candidates)
	var res [][]int
	var backtrack func(int, []int, int)

	backtrack = func(idx int, path []int, sum int) {
		if sum > target {
			return
		}
		if sum == target {
			// make a copy of the path and copy that path
			combo := make([]int, len(path))
			copy(combo, path)
			res = append(res, combo)
			return
		}

		for i := idx; i < n; i++ {
			path = append(path, candidates[i])    // push
			backtrack(i, path, sum+candidates[i]) // backtrack
			path = path[:len(path)-1]             // pop
		}
	}

	backtrack(0, []int{}, 0)

	return res
}
