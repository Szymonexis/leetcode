function rotate(nums: number[], k: number): void {
  const n = nums.length;
  k = ((k % n) + n) % n; // normalize to [0, n)

  const countGCD = (a: number, b: number): number =>
    b === 0 ? a : countGCD(b, a % b);

  const cycles = countGCD(n, k);

  for (let start = 0; start < cycles; start++) {
    let current = start;
    let prev = nums[start];

    while (true) {
      const next = (current + k) % n;
      const temp = nums[next];
      nums[next] = prev;
      prev = temp;
      current = next;

      if (current === start) break;
    }
  }
}


const expected: number[] = []
const nums: number[] = []
const k: number = null as unknown as number;
rotate(nums, k);
console.log(nums);

let correct = true;
for (let i = 0; i < nums.length; i++) {
	if (nums[i] !== expected[i]) {
		correct = false;
		break;
	}
}
console.log(correct);
