# 670. Maximum Swap
# https://leetcode.com/problems/maximum-swap/

import heapq

class Solution:
    def maximumSwap(self, num: int) -> int:
        digits = []
        while num > 0:
            digits.append(num % 10)
            num //= 10
        digits.reverse()
        print("digits=", digits)

        arr = [(-num, idx) for idx, num in enumerate(digits)]

        heapq.heapify(arr)

        curr_idx = 0
        swaps = 1
        while arr and swaps > 0:
            num,idx = heapq.heappop(arr)
            if curr_idx < idx:
                digits[curr_idx], digits[idx] = digits[idx], digits[curr_idx]
                swaps -= 1

        res = int(''.join(map(str, digits)))
        print("digits=", digits)
        return res



sol = Solution()
print(sol.maximumSwap(2736))
print(sol.maximumSwap(9973))
print(sol.maximumSwap(10))

