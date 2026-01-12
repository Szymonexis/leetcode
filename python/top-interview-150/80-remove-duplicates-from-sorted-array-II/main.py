from typing import List
from functools import reduce


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        non_dups = []
        curr: int | None = None
        count = 0
        for x in nums:
            if curr is None:
                curr = x
                count += 1
                continue

            if curr == x:
                count += 1
                continue

            if curr < x:
                for i in range(min(count, 2)):
                    non_dups.append(curr)
                curr = x
                count = 1

        for i in range(min(count, 2)):
            non_dups.append(curr)

        for i, x in enumerate(non_dups):
            nums[i] = x

        return len(non_dups)


nums = [1, 1, 1, 2, 2, 3]
nums = [0, 0, 1, 1, 1, 1, 2, 3, 3]

n = Solution().removeDuplicates(nums=nums)
nums_str = reduce(
    lambda acc, x: f"{acc}{"," if len(acc) != 0 else ""}{str(x[1]) if x[0] < n else "_"}",
    list(enumerate(nums)),
    "",
)
print(f"{n}, nums = [{nums_str}]")
