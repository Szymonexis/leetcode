// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

// Example 1:
// Input: nums = [3,2,3]
// Output: 3

// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
function majorityElement(nums: number[]): number {
    const map: Record<number, number> = {};
    for (const num of nums) {
      map[num] = (map[num] ?? 0) + 1;

      if ((map[num] ?? 0) >= nums.length / 2) {
        return num;
      }
    }

    let max = Number.NEGATIVE_INFINITY;
    let value = Number.NEGATIVE_INFINITY;
    for (const [v, c] of Object.entries(map)) {
      if (c > max) {
        max = c;
        value = Number(v);
      }
    }

    return value;
};