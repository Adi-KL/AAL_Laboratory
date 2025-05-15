#include <stdio.h>

void heapSort(int arr[], int n) {
    int i, j, temp;
  
    for (i = n / 2 - 1; i >= 0; i--) {
        int root = i;

        while (1) {
            int left = 2 * root + 1;
            int right = 2 * root + 2;
            int largest = root;

            if (left < n && arr[left] > arr[largest])
                largest = left;
            if (right < n && arr[right] > arr[largest])
                largest = right;

            if (largest != root) {
                temp = arr[root];
                arr[root] = arr[largest];
                arr[largest] = temp;
                root = largest;
            } else {
                break;
            }
        }
    }

    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        int root = 0;
        int heapSize = i;

        while (1) {
            int left = 2 * root + 1;
            int right = 2 * root + 2;
            int largest = root;

            if (left < heapSize && arr[left] > arr[largest])
                largest = left;
            if (right < heapSize && arr[right] > arr[largest])
                largest = right;

            if (largest != root) {
                temp = arr[root];
                arr[root] = arr[largest];
                arr[largest] = temp;
                root = largest;
            } else {
                break;
            }
        }
    }
}

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
