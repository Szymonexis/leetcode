from typing import List
from functools import reduce


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        non_dups = []
        for x in nums:
            if len(non_dups) == 0 or non_dups[-1] != x:
                non_dups.append(x)

        for i, x in enumerate(non_dups):
            nums[i] = x

        return len(non_dups)


nums = [1, 1, 2]
nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]


n = Solution().removeDuplicates(nums=nums)
nums_str = reduce(
    lambda acc, x: f"{acc}{"," if len(acc) != 0 else ""}{str(x[1]) if x[0] < n else "_"}",
    list(enumerate(nums)),
    "",
)
print(f"{n}, nums = [{nums_str}]")
