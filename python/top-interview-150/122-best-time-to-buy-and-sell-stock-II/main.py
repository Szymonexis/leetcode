from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        curr_min_i = 0
        curr_max_i = 0
        curr_min = float("inf")
        curr_max = float("-inf")
        mode = "find_min"
        for i, x in enumerate(prices):
            match mode:
                case "find_min":
                    if curr_min > x:
                        curr_min = x
                        curr_min_i = i
                    else:
                        curr_max = x
                        curr_max_i = i
                        mode = "find_max"

                case "find_max":
                    if curr_max < x:
                        curr_max = x
                        curr_max_i = i
                    else:
                        profit += curr_max - curr_min
                        curr_min = x
                        curr_min_i = i
                        mode = "find_min"

        if curr_max > curr_min and curr_min_i < curr_max_i:
            profit += curr_max - curr_min

        return profit


prices = [7, 1, 5, 3, 6, 4]
prices = [1, 2, 3, 4, 5]
prices = [7, 6, 4, 3, 1]
print(Solution().maxProfit(prices=prices))
