// 77. Combinations
// https://leetcode.com/problems/combinations

func combine(n int, k int) [][]int {

	var res [][]int
	var backtrack func(int, []int)

	backtrack = func(idx int, path []int) {
		if len(path) == k {
			temp := make([]int, k)
			copy(temp, path)
			res = append(res, temp)
			return
		}
		for i := idx; i <= n; i++ {
			path = append(path, i)    // push
			backtrack(i+1, path)      // backtrack
			path = path[:len(path)-1] //pop
		}
	}
	backtrack(1, []int{})

	return res
}
