from typing import List
from functools import reduce


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        nums_copy = nums[0:]

        i = 0
        count = 0
        for x in nums_copy:
            if x != val:
                nums[i] = x
                i += 1
            else:
                count += 1
        return len(nums) - count


nums = [3, 2, 2, 3]
val = 3

nums = [0, 1, 2, 2, 3, 0, 4, 2]
val = 2

n = Solution().removeElement(nums=nums, val=val)
nums_str = reduce(
    lambda acc, x: f"{acc}{"," if len(acc) != 0 else ""}{str(x[1]) if x[0] < n else "_"}",
    list(enumerate(nums)),
    "",
)
print(f"{n}, nums = [{nums_str}]")
