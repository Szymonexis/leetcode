from typing import List
from functools import reduce


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        l = [1] * n
        r = [1] * n
        answer = [0] * n

        for i in range(1, n):
            num = nums[i - 1]
            l[i] = l[i - 1] * num

        for i in range(n - 1, 0, -1):
            num = nums[i]
            r[i - 1] = r[i] * num

        for i in range(n):
            answer[i] = l[i] * r[i]

        return answer


class IncorrectSolution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        whole_product = reduce(lambda acc, x: acc * x, nums, 1)
        return list(map(lambda x: whole_product // x, nums))


nums = [1, 2, 3, 4]
expected = [24, 12, 8, 6]

# nums = [-1, 1, 0, -3, 3]
# expected = [0, 0, 9, 0, 0]

sol = Solution().productExceptSelf(nums=nums)
incorrect_sol = IncorrectSolution().productExceptSelf(nums=nums)
print(
    f"Solution\nnums = {nums}\n expected = {expected} \n sol = {sol}\n Correct? {incorrect_sol == expected}"
)
print("---")
print(
    f"IncorrectSolution\nnums = {nums}\n expected = {expected} \n sol = {incorrect_sol}\n Correct? {incorrect_sol == expected}"
)
