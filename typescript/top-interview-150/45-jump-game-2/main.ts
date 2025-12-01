/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. 
In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n

Return the minimum number of jumps to reach index n - 1. 
The test cases are generated such that you can reach index n - 1.
*/

function jump(nums: number[]): number {
	if (nums.length <= 1) return 0;

	let jumps = 0;
	let currentEnd = 0; // end of the range for current jump
	let farthest = 0; // farthest position we can reach

	// we dont need to jump from the last index
	for (let i = 0; i < nums.length - 1; i++) {
		// update the farthest position we can reach
		farthest = Math.max(farthest, i + nums[i]);

		// if weve reached the end of the current jump range
		if (i === currentEnd) {
			jumps++;
			currentEnd = farthest;

			// if we can already reach the end, break
			if (currentEnd >= nums.length - 1) break;
		}
	}

	return jumps;
}
