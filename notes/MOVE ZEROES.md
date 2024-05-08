Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.

SIMPLE SOLUTION (TWO POINTERS)
```c
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void moveZeroes(int *nums, int numsSize) {
	int j = 0;
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] != 0) {
			swap(&nums[i], &nums[j]);
			j++;
		}
	}
}
```