#include <stdio.h>
#include <stdbool.h>

bool binary_search(int haystack[], int needle, int length);

int main() {

    int arr[] = {
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        11, 12, 13, 14, 15,
    };
    int length = *(&arr + 1) - arr;
    int target = 11;

    binary_search(arr, target, length);
    return 0;
}

bool binary_search(int haystack[], int needle, int length) {

    int low = 0;
    int hi = length;

    do {
        int m = low + ((hi - low) / 2);
        int v = haystack[m];

        if (v == needle) {
            printf("haystack[%d]: %d\n", m, v);
            return true;
        } else if (v > needle) {
            hi = m;
        } else {
            low = m + 1;
        }
    } while (hi > low);

    return false;
}
