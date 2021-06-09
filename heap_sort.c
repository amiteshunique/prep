#include<stdio.h>

void print_arr(int arr[], int n) {
        for(int i=0; i<n; i++) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2*i +1;
        int right = 2*i +2;

        if(left<n && arr[largest] < arr[left]) {
                largest = left;
        }

        if(right<n && arr[largest] < arr[right]) {
                largest = right;
        }

        if(largest != i) {
                int temp = arr[i];
                arr[i] = arr[largest];
                arr[largest] = temp;
                heapify(arr, n, largest);
                print_arr(arr, n);
        }
}

void heap_sort(int arr[], int n) {
        for(int i=n-1; i>0; i--) {
                int temp = arr[i];
                arr[i] = arr[0];
                arr[0] = temp;
                heapify(arr, i, 0);
        }
}

int main() {
        int arr[] = {6,1,3,7,4,5,2,10};
        int n = sizeof(arr)/sizeof(int);

        /* Make a Max Heap */
        print_arr(arr, n);
        for(int i=(n-2)/2; i>=0; i--) {
                heapify(arr, n, i);
        }

        print_arr(arr, n);
        heap_sort(arr, n);
        print_arr(arr, n);

}
