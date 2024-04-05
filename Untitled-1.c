#include <stdio.h>

double sum(double arr[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    double numbers[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    double total = sum(numbers, size);
    printf("Sum of elements in the array: %f\n", total);
    return 0;
}
