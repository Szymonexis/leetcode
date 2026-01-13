from typing import List

# Greedy, 
# time complexity: O(n), 
# space complexity: O(1)
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        if sum(gas) < sum(cost):
            return -1

        total = 0
        result = 0
        for i in range(n):
            total += gas[i] - cost[i]

            if total < 0:
                total = 0
                result = i + 1
        return result


gas = [1, 2, 3, 4, 5]
cost = [3, 4, 5, 1, 2]
expected = 3
sol = Solution().canCompleteCircuit(gas=gas, cost=cost)

gas = [2, 3, 4]
cost = [3, 4, 3]
expected = -1
sol = Solution().canCompleteCircuit(gas=gas, cost=cost)

print(
    f"""gas = {gas}
cost = {cost}
sol = {sol}
expected = {expected}
is_correct = {sol == expected}"""
)
