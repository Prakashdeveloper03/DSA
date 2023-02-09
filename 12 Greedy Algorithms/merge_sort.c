#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    int i,j;
	if (l < r) {
        int m = l + (r - l) / 2;

        printf("Divide: ");
        for ( i = l; i <= r; i++)
            printf("%d ", arr[i]);
        printf("\n");

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        printf("Conquer: ");
        for (i = l; i <= r; i++)
            printf("%d ", arr[i]);
        printf("\n");

        merge(arr, l, m, r);
    }
}

int main() {
    int arr[20];
     int i,n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter array Elements:");
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    printf("Original array: ");
    for ( i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
