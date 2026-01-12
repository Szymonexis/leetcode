from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        nums1_copy = nums1[:m]

        i = 0
        j = 0
        k = 0
        while i < m and j < n:
            if nums1_copy[i] <= nums2[j]:
                nums1[k] = nums1_copy[i]
                i += 1
            elif nums2[j] < nums1_copy[i]:
                nums1[k] = nums2[j]
                j += 1
            k += 1

        if i < m:
            for i_2 in range(i, m):
                nums1[k] = nums1_copy[i_2]
                k += 1

        if j < n:
            for j_2 in range(j, n):
                nums1[k] = nums2[j_2]
                k += 1


nums1 = [1, 2, 3, 0, 0, 0]
m = 3
nums2 = [2, 5, 6]
n = 3

nums1 = [1]
m = 1
nums2 = []
n = 0

nums1 = [0]
m = 0
nums2 = [1]
n = 1

Solution().merge(nums1=nums1, nums2=nums2, n=n, m=m)
print(nums1)
