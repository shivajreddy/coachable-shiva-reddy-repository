// 496. Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i/description/

package main

import (
	"fmt"
)

func nextGreaterElement(nums1 []int, nums2 []int) []int {
	hm := make(map[int]int)
	stack := []int{}

	// Process all elements in nums2
	for _, num := range nums2 {
		// Pop elements from stack and assign current num as their next greater element
		for len(stack) > 0 && num > stack[len(stack)-1] {
			top := stack[len(stack)-1]
			hm[top] = num
			stack = stack[:len(stack)-1]
		}
		// Push current number to stack
		stack = append(stack, num)
	}

	// For all remaining elements in stack, there's no greater element
	for _, num := range stack {
		hm[num] = -1
	}

	// Build result array
	res := make([]int, len(nums1))
	for i, num := range nums1 {
		res[i] = hm[num]
	}

	return res
}

func main() {

	// TEST 1
	fmt.Println(nextGreaterElement([]int{4, 1, 2}, []int{1, 3, 4, 2}))
	fmt.Print([]int{-1, 3, -1}, "\n\n")

	// TEST 2
	fmt.Println(nextGreaterElement([]int{2, 4}, []int{1, 2, 3, 4}))
	fmt.Print([]int{3, -1}, "\n\n")

	// TEST 3
	fmt.Println(nextGreaterElement([]int{1, 3, 5, 2, 4}, []int{5, 4, 3, 2, 1}))
	fmt.Print([]int{-1, -1, -1, -1, -1}, "\n\n")
}
