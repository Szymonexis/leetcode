from typing import List


class OptimalSolution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        paper_counts = [0 for _ in range(n + 1)]
        for c in citations:
            paper_counts[min(c, n)] += 1

        h = n
        papers = paper_counts[n]
        while papers < h:
            h -= 1
            papers += paper_counts[h]

        return h


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        papers = len(citations)
        possible_h_indexes = [0 for _ in range(papers)]
        for x in citations:
            for i in range(min(x, papers)):
                possible_h_indexes[i] += 1

        prev = 0
        for i, x in enumerate(possible_h_indexes):
            if i + 1 == x:
                return x
            if i + 1 > x:
                return prev
            prev = i + 1
        return prev


citations = [3, 0, 6, 1, 5]
expected = 3

# citations = [1, 3, 1]
# expected = 1

optimal_sol = OptimalSolution().hIndex(citations=citations)
sol = Solution().hIndex(citations=citations)
print(f"Solution: {sol}, Expected: {expected}, Correct?: {sol == expected}")
print(
    f"OptimalSolution: {optimal_sol}, Expected: {expected}, Correct?: {optimal_sol == expected}"
)
