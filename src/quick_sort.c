#include <stdio.h>

// Let's implement a Quick Sort algorithm

void swap(int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(int arr[], int lo, int hi) {

    // picking our pivot
    // it could be anything
    // the middle item
    // or any other item
    int pivot = arr[hi];
    int idx = lo - 1;

    // sorting based on out pivot
    for (int i = lo; i < hi; ++i) {
        if (arr[i] <= pivot) {
            idx++;
            swap(arr, i, idx);
        }
    }

    // this idx position is next to
    // the item lower than the pivot
    idx++;

    // positioning our pivot to come after
    // anything lower and before anything higher
    swap(arr, hi, idx);

    // return the index of our pivot
    return idx;
}

void quick_sort(int arr[], int lo, int hi) {

    // base case
    if (lo >= hi) return;

    // the index of our pivot will be our point of reference
    // anything before must be lower in value
    // anything after must be higher in value
    int pivotIdx = partition(arr, lo, hi);

    // recursion before the pivot
    quick_sort(arr, lo, pivotIdx - 1);

    // recursion after the pivot
    quick_sort(arr, pivotIdx + 1, hi);
}

void print_array(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        if (i == 0) {
            printf("{ %d, ", arr[i]);
        } else if (i == length - 1) {
            printf("%d }\n", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
}

int main() {

    int arr[] = { 9, 3, 7, 4, 69, 420, 42 };
    int hi = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, hi);
    quick_sort(arr, 0, hi);
    print_array(arr, hi);

    return 0;
}
