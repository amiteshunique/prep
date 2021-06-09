//https://www.youtube.com/watch?v=J2Er5XceU_I&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=16

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SZ 3
void perm(char arr[], char op[], int s) {
        if (s == SZ) {
                op[s] = '\0';
                printf("%s \n", op, s);
                return;
        }

        char *op1 = (char*) malloc(sizeof(char) * (SZ+1) );
        char *op2 = (char*) malloc(sizeof(char) * (SZ+1) );

        memcpy(op1, op, s);
        memcpy(op2, op, s);

        op1[s] = arr[s];
        perm(arr, op1, s+1);

        op2[s] = arr[s] - 'a' + 'A';
        perm(arr, op2, s+1);
}

int main() {
        char arr[] = {'t', 'i', 'j', '\0'};

        char op[SZ+1];
        perm(arr, op, 0);
}
~
