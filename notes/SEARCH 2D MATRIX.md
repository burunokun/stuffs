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