// 388. Longest Absolute File Path
// https://leetcode.com/problems/longest-absolute-file-path
package main

import (
	"strings"
)

func lengthLongestPath(input string) int {

	lines := strings.Split(input, "\n")

	stack := make([]int, len(lines)) // current path lengths

	result := 0 // max width of absolute-path to a file

	for _, line := range lines {
		tab_count := strings.Count(line, "\t")
		name := strings.Trim(line, "\t")
		current_path_width := 0
		if tab_count > 0 {
			current_path_width = stack[tab_count-1] + len(name) + 1
		} else {
			current_path_width = len(name)
		}

		stack[tab_count] = current_path_width

		if strings.Contains(name, ".") { // update global result if current path is a file
			result = max(result, current_path_width)
		}
	}

	return result
}
