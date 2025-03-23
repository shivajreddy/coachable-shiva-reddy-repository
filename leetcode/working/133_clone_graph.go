// 133. Clone Graph
// https://leetcode.com/problems/clone-graph/description/
package main

type Node struct {
	Val       int
	Neighbors []*Node
}

func cloneGraph(node *Node) *Node {
	if node == nil {
		return nil
	}

	visited := make(map[int]*Node)

	// DFS: PreOrder
	var clone func(node *Node) *Node
	clone = func(node *Node) *Node {
		if val, exists := visited[node.Val]; exists {
			return val
		}
		newNode := &Node{
			Val:       node.Val,
			Neighbors: make([]*Node, 0, len(node.Neighbors)),
		}

		// Process Current
		visited[node.Val] = newNode

		// Process children
		for _, neighbor := range node.Neighbors {
			newNode.Neighbors = append(newNode.Neighbors, clone(neighbor))
		}
		return newNode
	}
	return clone(node)
}
