#include<stdio.h>
int n=10;
void merge(int *arr, int s, int m, int e) {
        int n1 = m-s+1;
        int n2 = e-m;

        int left[n1];
        int right[n2];
        int i, j, k;

        for(i=0; i<n1; i++)
                left[i] = arr[s+i];

        for(j=0; j<n2; j++)
                right[j] = arr[m+1+j];

        i=j=0;
        k=s;
        while(i<n1 && j<n2) {
                if(left[i] <= right[j])
                        arr[k++] = left[i++];
                else
                        arr[k++] = right[j++];
        }

        while(i<n1)
                arr[k++] = left[i++];

        while(j<n2)
                arr[k++] = right[j++];
}

void merge_sort(int arr[], int s, int e) {
        if(s<e) {
                int mid = s + (e-s)/2;
                merge_sort(arr, s, mid);
                merge_sort(arr, mid+1, e);
                merge(arr, s, mid, e);
        }
}

int main() {
        int arr[] = {9, 5, 1, 2, 4, 3, -1, 0, 1, -100};
        int n = 10;
        for(int i=0; i<n; i++)
                printf("%d ", arr[i]);

        printf("\n");
        merge_sort(arr, 0, n-1);

        for(int i=0; i<n; i++)
                printf("%d ", arr[i]);

        printf("\n");
}
