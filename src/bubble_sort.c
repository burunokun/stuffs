#include <stdio.h>
#include <math.h>

void bubble_sort(int arr[], int length);
void print_array(int arr[], int length);

int main() {

    printf("Sorting algorithm: Bubble sort\n");
    int arr[] = {3, 4, 1, 2, 5};
    int length = *(&arr + 1) - arr;

    printf("Before:\t");
    print_array(arr, length);

    bubble_sort(arr, length);

    printf("After:\t");
    print_array(arr, length);

    return 0;
}

void bubble_sort(int arr[], int length) {

    int i, j;
    for (i = 0; i < length; ++i) {
        for (j = 0; j < length - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

}

void print_array(int arr[], int length) {

    for (int i = 0; i < length; ++i) {
        if (i == 0) printf("{");
        if (i + 1 == length) {
            printf("%d}\n", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
}
