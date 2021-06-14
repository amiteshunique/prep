#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SZ 4
int total_subset = 0;
void print_output(int op[], int x) {
        if(x==-1)
                printf("NULL");

        for (int i=0; i<=x; i++)
                printf("%d ", op[i]);

        printf("\n");
        total_subset++;
}

void subset(int arr[], int n, int op[], int x) {
        if (n==-1) {
                print_output(op, x);
                return;

        }

        int op1[SZ], op2[SZ];
        memcpy(op1, op, sizeof(int) * (x+1) );
        memcpy(op2, op, sizeof(int) * (x+1) );

        op2[x+1] = arr[n];
        subset(arr, n-1, op1, x);
        subset(arr, n-1, op2, x+1);
}

int main() {
        int arr[] = {4, 3, 2, 1};
        int n = SZ;

        int temp[SZ];
        subset(arr, SZ-1, temp, -1); //0-indexed
        printf("\nTotal Subsets: %d\n", total_subset);
}
