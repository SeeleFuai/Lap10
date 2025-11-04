#include <stdio.h>

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Hàm gộp hai mảng đã sắp xếp
void merge(int arr[], int l, int m, int r, int n) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[(m + 1) + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    // In trạng thái mảng sau mỗi lần gộp
    printf("Sau khi gop tu %d den %d: ", l, r);
    printArray(arr, n);
}

// Hàm Merge Sort đệ quy
void mergeSort(int arr[], int l, int r, int n) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, n);
        mergeSort(arr, m + 1, r, n);

        merge(arr, l, m, r, n);
    }
}

// Hàm main
int main() {
    int arr[] = {3, 6, 1, -1, 0, 5, 8, 2, 4, 8, 29, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang ban dau: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1, n);

    printf("\nMang sau khi sap xep: ");
    printArray(arr, n);

    return 0;
}
