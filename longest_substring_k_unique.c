#include<stdio.h>
#include<stdlib.h>
int count_arr(char *arr) {
        int sum = 0;
        for(int i=0; i<26; i++) {
                if( arr[i] != 0 )
                        sum++;
        }

        return sum;
}
int main() {
        char arr[] = {'a', 'b', 'e', 'b', 'd', '\0'};
        int n = sizeof(arr)/sizeof(char);
        int k = 2;
        printf("Input: <%s> for k=%d\n", arr, k);

        char *c = (char*) calloc(sizeof(char), 26);
        int i=0, j=0;
        int max = 0;
        while(j < n) {
                c[ arr[j] - 'a'] += 1;

                if ( count_arr(c) < k) {
                        j++;
                } else if (count_arr(c) == k) {
                        printf("%d-%d\n", i,j);
                        max = max > (j-i+1) ? max : (j-i+1);
                        j++;
                } else if (count_arr(c) > k) {
                        while ( count_arr(c) > k ) {
                                c[ arr[i] - 'a'] -= 1;
                                i++;

                        }

                        if (count_arr(c) == k) {
                                printf("%d-%d\n", i,j);
                                max = max > (j-i+1) ? max : (j-i+1);
                        }

                        j++;
                }
        }
        printf("Max= %d\n", max);
        return 0;
}
