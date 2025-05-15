#include <stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
     for (i = 0; i < n - 1; i++) {
     for (j = 0; j < n - i - 1; j++) {
     if (arr[j] > arr[j + 1]) {
      // Swapping values
      temp = arr[j];
      arr[j] = arr[j + 1];
      arr[j + 1] = temp;
       }
     }
  }
}


void printArray(int arr[], int n) {
    int i;
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[100], n, i;
  
   printf("Enter number of elements: ");
   scanf("%d", &n);
  printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
  bubbleSort(arr, n);
  printArray(arr, n);
  return 0;
}
