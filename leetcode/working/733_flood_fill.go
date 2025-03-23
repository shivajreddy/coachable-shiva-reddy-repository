package main

import (
	"fmt"
)

// USING DFS
/*
func dfs(image [][]int, sr int, sc int, target int, color int) {
	// Out of bounds
	if sr < 0 || sr >= len(image) || sc < 0 || sc >= len(image[0]) {
		return
	}
	// Already changed color
	if image[sr][sc] == color {
		return
	}
	// Not of the same color that has to be flooded
	if image[sr][sc] != target {
		return
	}

	// Flood the color
	image[sr][sc] = color

	// Explore all other directions
	dfs(image, sr+1, sc, target, color)
	dfs(image, sr-1, sc, target, color)
	dfs(image, sr, sc+1, target, color)
	dfs(image, sr, sc-1, target, color)
}

func floodFill(image [][]int, sr int, sc int, color int) [][]int {
	target := image[sr][sc]
	dfs(image, sr, sc, target, color)

	return image
}
*/

// USING BFS
func floodFill(image [][]int, sr int, sc int, color int) [][]int {
	// Early return if the starting pixel is already the target color
	if image[sr][sc] == color {
		return image
	}

	target := image[sr][sc]
	rows, cols := len(image), len(image[0])

	// Directions: right, left, down, up
	directions := [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}

	// Queue for BFS
	queue := [][]int{{sr, sc}}

	// Change the starting pixel
	image[sr][sc] = color

	for len(queue) > 0 {
		// Dequeue
		curr := queue[0]
		queue = queue[1:]

		// Check all four directions
		for _, dir := range directions {
			newRow, newCol := curr[0]+dir[0], curr[1]+dir[1]

			// Check bounds, target color, and not already processed
			if newRow >= 0 && newRow < rows &&
				newCol >= 0 && newCol < cols &&
				image[newRow][newCol] == target {

				// Change color and enqueue
				image[newRow][newCol] = color
				queue = append(queue, []int{newRow, newCol})
			}
		}
	}

	return image
}

func printImage(image [][]int) {
	for _, row := range image {
		fmt.Println(row)
	}
	fmt.Println("")
}

func main() {
	// TEST 1
	image := [][]int{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}
	printImage(image)
	floodFill(image, 1, 1, 2)
	printImage(image)
}
