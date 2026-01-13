from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        candy = [1] * len(ratings)

        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candy[i] = candy[i - 1] + 1

        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candy[i] = max(candy[i], candy[i + 1] + 1)

        return sum(candy)


# ratings = [1, 0, 2]
# expected = 5
# sol = Solution().candy(ratings=ratings)


# ratings = [1, 2, 2]
# expected = 4
# sol = Solution().candy(ratings=ratings)


ratings = [1, 2, 87, 87, 87, 2, 1]
expected = 13
sol = Solution().candy(ratings=ratings)


# ratings = [1, 3, 4, 5, 2]
# expected = 11
# sol = Solution().candy(ratings=ratings)


print(f"expected = {expected}\nsol = {sol}\nIs correct? {expected == sol}")
