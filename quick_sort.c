#include<stdio.h>
void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
}

int n = 7;
int partition(int arr[], int s, int e) {
        int pivot = arr[e];
        int i=s-1;
        for(int j=s; j<=e-1; j++) {
                if(arr[j] < pivot) {
                        i++;
                        swap(&arr[i], &arr[j]);
                }
        }
        swap(&arr[i+1], &arr[e]);
        return (i+1);
}

void qsort(int arr[], int s, int e) {
        if(s<e) {
                int p = partition(arr, s, e);
                qsort(arr, s, p-1);
                qsort(arr, p+1, e);
        }
}

int main() {
        int arr[] = {-100, 4, 3, 9, 1, 5, 100};
        int n = 7;
        qsort(arr, 0, n-1);

        for(int i=0;i<n;i++)
                printf("%d ", arr[i]);

        printf("\n");
        return 0;
}
