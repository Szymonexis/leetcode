from typing import List
import time


class BruteForceSolution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        smallest = [float("inf")]

        def backtrack(i=0, jumps=0):
            if i == n - 1:
                smallest[0] = min(smallest[0], jumps)
                return

            max_jump = nums[i]
            max_reachable = min(i + max_jump, n - 1)

            for new_index in range(max_reachable, i, -1):
                backtrack(new_index, jumps + 1)

        backtrack()
        return smallest[0]


class Solution:
    """
    nums = [2, 3, 0, 0, 2, 1, 4]

    0. Initialization — start at index 0 with no jumps and no reach
       i = 0
       far = 0
       end = 0
       jumps = 0

    1. First jump window defined — reach as far as nums[0] allows
       i = 0
       far = 2
       end = 2
       jumps = 1

    2. Extend reach inside current window — maximize future jump range
       i = 1
       far = 4
       end = 2
       jumps = 1

    3. Window exhausted — commit jump and move window forward
       i = 2
       far = 4
       end = 4
       jumps = 2

    4. Continue scanning current window — no better reach found
       i = 3
       far = 4
       end = 4
       jumps = 2

    5. New maximum reach found — next jump reaches the end
       i = 4
       far = 6
       end = 6
       jumps = 3

    6. Final scan before end — already within last jump window
       i = 5
       far = 6
       end = 6
       jumps = 3
    """

    def jump(self, nums: List[int]) -> int:
        jumps = 0
        n = len(nums)
        end, far = 0, 0

        for i in range(n - 1):
            far = max(far, i + nums[i])

            if i == end:
                jumps += 1
                end = far

        return jumps


nums = [2, 3, 1, 1, 4]
expected = 2

nums = [2, 3, 0, 1, 4]
expected = 2

nums = [1, 1, 1, 1]
expected = 3

nums = [2, 3, 0, 0, 2, 1, 4]
expected = 3

brute_force_sol_start_ms = time.time_ns() / 1_000_000
brute_force_sol = BruteForceSolution().jump(nums=nums)
brute_force_sol_end_ms = time.time_ns() / 1_000_000

sol_start_ms = time.time_ns() / 1_000_000
sol = Solution().jump(nums=nums)
sol_end_ms = time.time_ns() / 1_000_000
print(
    f"Brute Force Solution [{sol}] is correct? {expected == brute_force_sol}; time: {brute_force_sol_end_ms - brute_force_sol_start_ms} ms"
)
print(
    f"Solution [{sol}] is correct? {expected == sol}; time: {sol_end_ms - sol_start_ms} ms"
)
