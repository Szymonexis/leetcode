from typing import List, Dict


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        min_price = float("inf")
        for x in prices:
            min_price = min(min_price, x)
            max_profit = max(x - min_price, max_profit)
        return max_profit


prices = [7, 1, 5, 3, 6, 4]
prices = [7, 6, 4, 3, 1]

print(Solution().maxProfit(prices=prices))
