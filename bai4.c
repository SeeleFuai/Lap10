#include <stdio.h>
#include <stdlib.h>

// Hàm so sánh giảm dần (cho số dương)
int cmpDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Hàm so sánh tăng dần (cho số âm)
int cmpAsc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap %d so nguyen:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Tách các phần tử thành 3 nhóm
    int pos[n], neg[n], zero[n];
    int p = 0, q = 0, z = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            pos[p++] = arr[i];
        else if (arr[i] < 0)
            neg[q++] = arr[i];
        else
            zero[z++] = arr[i];
    }

    // Sắp xếp các nhóm
    qsort(pos, p, sizeof(int), cmpDesc); // dương giảm
    qsort(neg, q, sizeof(int), cmpAsc);  // âm tăng

    // Ghép lại mảng theo thứ tự yêu cầu
    int result[n], idx = 0;

    for (int i = 0; i < p; i++)
        result[idx++] = pos[i];
    for (int i = 0; i < z; i++)
        result[idx++] = zero[i];
    for (int i = 0; i < q; i++)
        result[idx++] = neg[i];

    // In kết quả
    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
    printf("\n");

    return 0;
}
