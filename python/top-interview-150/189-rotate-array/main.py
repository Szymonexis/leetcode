from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        rotated = []
        offset = (len(nums) - k) % len(nums)
        for x in nums[offset : len(nums)]:
            rotated.append(x)
        for x in nums[0:offset]:
            rotated.append(x)

        for i, x in enumerate(rotated):
            nums[i] = x


nums = [1, 2, 3, 4, 5, 6, 7]
k = 3
expected = [5, 6, 7, 1, 2, 3, 4]

nums = [-1, -100, 3, 99]
k = 2
expected = [3, 99, -1, -100]

Solution().rotate(nums=nums, k=k)
print(f"{nums}")
print(nums == expected)
