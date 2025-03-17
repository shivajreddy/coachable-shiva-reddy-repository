# 398. Random Pick Index
# https://leetcode.com/problems/random-pick-index/description/

import random
from typing import List

class Solution:
    def __init__(self, nums: List[int]):
        self.num_to_indices = {}
        for idx, num in enumerate(nums):
            if num not in self.num_to_indices:
                self.num_to_indices[num] = []
            self.num_to_indices[num].append(idx)

    def pick(self, target: int) -> int:
        # Retrieve the list of indices for the target
        indices = self.num_to_indices.get(target, [])
        # Randomly select and return one of the indices
        return random.choice(indices)
