function rotate(nums: number[], p_k: number): void {
	const l = nums.length;
	const k = (p_k % l);

	if (k === 0 || k === nums.length) {
		return;
	}

	
}

const nums = [1, 2, 3, 4, 5, 6, 7];
const k = 2;
rotate(nums, k);
