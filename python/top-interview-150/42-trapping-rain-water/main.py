from typing import List


def visualize_stacks(height: List[int], rain: List[int], step: str = ""):
    """Visualize height and rain arrays as stacks of blocks in terminal"""
    if not height:
        return

    max_height = max(max(height), max(rain) if rain else 0)
    n = len(height)

    if step:
        print(f"\n{step}")

    # Print from top to bottom
    for level in range(max_height, 0, -1):
        height_row = ""
        rain_row = ""

        for i in range(n):
            if height[i] >= level:
                height_row += "█ "
            else:
                height_row += "  "

            if rain[i] >= level:
                rain_row += "░ "
            else:
                rain_row += "  "

        print(f"  {height_row}    {rain_row}")

    # Print indices
    indices = "  " + " ".join(str(i % 10) for i in range(n))
    print(f"{indices}   {indices}")
    print(f"  height{' ' * (n * 2 - 6)}    rain")


class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n <= 0:
            return 0

        l, r = 0, n - 1
        l_max, r_max = height[l], height[r]
        res = 0

        # rain = [0] * n
        # visualize_stacks(height, rain, "Initial state:")

        step = 0
        while l < r:
            step += 1

            if l_max < r_max:
                l += 1
                l_max = max(l_max, height[l])
                res += l_max - height[l]
                # rain[l] = l_max
                # visualize_stacks(
                #     height, rain, f"Step {step}: moved left pointer to index {l}"
                # )
            else:
                r -= 1
                r_max = max(r_max, height[r])
                res += r_max - height[r]
                # rain[r] = r_max
                # visualize_stacks(
                #     height, rain, f"Step {step}: moved right pointer to index {r}"
                # )

        return res


class BadSolution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        rain_l = [0] * n
        rain_r = [0] * n
        rain = [0] * n

        for i in range(1, n):
            rain_l[i] = max(rain_l[i - 1], height[i])

        for i in range(n - 2, -1, -1):
            rain_r[i] = max(rain_r[i + 1], height[i])

        for i in range(n):
            rain[i] = min(rain_l[i], rain_r[i])

        for i in range(n):
            rain[i] = max(rain[i] - height[i], 0)

        return sum(rain)


height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
expected = 6
sol = Solution().trap(height=height)
BadSolution().trap(height=height)
print(
    f"\nheight = {height}\nexpected = {expected}\nsol = {sol}\nis correct? {sol == expected}"
)
