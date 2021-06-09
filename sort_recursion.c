#include <stdio.h>

void print_arr(int arr[], int n) {
        for(int i=0; i<=n; i++) {
                printf("%d  ", arr[i]);
        }
        printf("\n");
}

void insert(int arr[], int n, int k) {
        if(n==-1) {
                arr[0] = k;
                return;
        }

        if (arr[n] < k) {
                arr[n+1] = k;
                return;
        }

        int temp = arr[n];
        insert(arr, n-1, k);
        arr[n+1] = temp;
}

void sort(int arr[], int n) {
        if (n==0)
                return;

        int temp = arr[n];
        sort(arr, n-1);
        insert(arr, n-1, temp);
}

int main(){
        int arr[] = {4, 3, 1, 2, -15, 0};
        int n = 5;              //Considering 0-indexing.

        printf("Given: ");
        print_arr(arr, n);

        sort(arr, n);

        printf("Solution: ");
        print_arr(arr, n);
}
