#include<stdio.h>
#include<stdlib.h>

void reverse(int *arr, int n) {
        for(int i=0; i<n/2;i++) {
                int temp = arr[n-i-1];
                arr[n-i-1] = arr[i];
                arr[i] = temp;
        }
}

/*
 * Input no. of elements and array.
 * And reverse the input array.
 */
int main() {
        int *arr, n;
        scanf("%d", &n);
        arr = (int *) malloc(sizeof(int) * n);
        for(int i=0; i<n; i++) {
                scanf("%d", &arr[i]);
        }

        for(int i=0; i<n; i++) {
                printf("%d ", arr[i]);
        }
        printf("\nResult:");

        reverse(arr, n);

        for(int i=0; i<n; i++) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}
