#include "binary_search.h"

int *binary_search(int value, const int *arr, size_t length) {
        int low = 0;
        int high = length - 1;

        while (low <= high) {
            int middle = (low + high) / 2;

            if (arr[middle] == value) {
                return (int *) &arr[middle];
            }

            if (value < arr[middle]) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }

        }

        return NULL;
}
