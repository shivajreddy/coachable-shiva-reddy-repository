# 133. Clone Graph
# https://leetcode.com/problems/clone-graph

class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node: return None
        '''
        {
            <original_node_1> : <copy_node_1>,
            <original_node_2> : <copy_node_2>
        }
        '''
        visited = {}
        visited[node] = Node(node.val)              # make a copy of root node

        stack = [node]

        while stack:

            curr = stack.pop()

            for child in curr.neighbors:
                if child not in visited:
                    stack.append(child)
                    child_copy = Node(child.val)
                    visited[child] = child_copy
                visited[curr].neighbors.append(visited[child])

        
        return visited[node]
