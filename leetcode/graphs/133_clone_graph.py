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
        original_to_clone_map = {}

        stack = [node]  # original nodes that are to be cloned

        while stack:

            curr = stack.pop()
            original_to_clone_map[node] = Node(curr.val)              # make a copy of root node

            for child in curr.neighbors:
                if child not in original_to_clone_map:
                    stack.append(child)
                    child_copy = Node(child.val)
                    original_to_clone_map[child] = child_copy
                original_to_clone_map[curr].neighbors.append(original_to_clone_map[child])

        
        return original_to_clone_map[node]
