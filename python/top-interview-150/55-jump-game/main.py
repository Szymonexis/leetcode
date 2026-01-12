from typing import List


class Solution_1:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True

        max_jump = nums[0]
        for i, x in enumerate(nums):
            max_jump = max(max_jump, i + x)

            if max_jump == i and max_jump < len(nums) - 1:
                return False

        return max_jump >= len(nums) - 1


class Solution_2:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        target = n - 1

        for i in range(n - 1, -1, -1):
            max_jump = nums[i]
            if i + max_jump >= target:
                target = i

        return target == 0


nums = [2, 3, 1, 1, 4]
nums = [3, 2, 1, 0, 4]
print(Solution_1().canJump(nums=nums))
print(Solution_2().canJump(nums=nums))
