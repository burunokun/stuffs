### ARRAY
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

---
### 2D ARRAY

Description:
> You are given an `m x n` integer matrix `matrix` with the following two properties:
> - Each row is sorted in an non-decreasing order.
> - The first integer of each row is greater than the last integer of the previous row.
> Given an integer `target`, return `true` if `target` is in `matrix` or `false` otherwise.

Brute Force:
```c
bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target) {
	int row = 0;
	int col = *matrixColSize - 1;
	for (int i = 0; i < matrixSize; ++i) {
		if (matrix[i][col] <= target) {
			row = i; 
			break;
		}
	}
	for (int i = 0; i < col; ++i) {
		if (matrix[row][i] == target) return true;
	}
	return false;
}
```

Optimal Solution (Binary Search):
```c
bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target) {
	int i = 0;
	int j = *matrixColSize - 1;
	while (i < matrixSize && j >= 0) {
		if (matrix[i][j] == target) return true;
		if (matrix[i][j] < target) i++;
		else j--;
	}
	return false;
}
```

---

### INT 2D ARRAY
How to deal with LEETCODE's `int** returnColumnSizes`
```c
// this represents that the 2d array to be returned has n 1d arrays
*returnColumnSizes = malloc(n * sizeof(**returnColumnSizes));

// this represents the size of each 1d array within the 2d array
(*returnColumnSizes)[0] = n;
(*returnColumnSizes)[1] = n;

// or

// allocate a pointer of n arrays
int *temp = malloc(n * sizeof(*temp));
// memset to 0 (NULL) or use calloc instead
memset(temp, 0, (n * sizeof(*temp)))

// increase each pointer (treated as 1d array)
for (size_t i = 0; i < n; ++i) {
    col[0]++;
    col[1]++;
}
// assign back to represent each 1d array size within 2d array
*returnColumnSizes = col; 
```

