// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii

func combinationSum2(candidates []int, target int) [][]int {
	var res [][]int
	var backtrack func(idx int, path []int, sum int)

	sort.Ints(candidates) // sort the input, to handle duplicates efficiently

	backtrack = func(idx int, path []int, sum int) {
		if sum > target {
			return
		}
		if sum == target {
			combo := make([]int, len(path))
			copy(combo, path)
			res = append(res, combo) // add to result
			return
		}

		for i := idx; i < len(candidates); i++ {
			if i > idx && candidates[i] == candidates[i-1] {
				continue
			}
			if candidates[i] > target-sum {
				break
			}
			path = append(path, candidates[i])      // push
			backtrack(i+1, path, sum+candidates[i]) // backtrack
			path = path[:len(path)-1]               // pop
		}

	}

	backtrack(0, []int{}, 0)

	return res
}
