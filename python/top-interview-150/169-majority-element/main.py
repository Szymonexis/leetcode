from typing import List, Dict
import math


# majority element is an element that appears more than floor(n / 2) times
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counts_dict: Dict[int, int] = {}

        for x in nums:
            try:
                counts_dict[x] += 1
            except KeyError:
                counts_dict[x] = 1

        for key, val in counts_dict.items():
            if val > math.floor(len(nums) / 2):
                return key


nums = [3, 2, 3]
nums = [2, 2, 1, 1, 1, 2, 2]

sol = Solution().majorityElement(nums=nums)
print(sol)
