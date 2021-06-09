#include<stdio.h>
#include<string.h>
void swap(char *a, char *b) {
        char temp = *a;
        *a = *b;
        *b = temp;
}

void permutations(char *s, int start, int end) {
        if(start > end)
                return;

        if(start==end) {
                printf("%s\n", s);
                return;
        }

        for(int i=start; i<end; i++) {
                permutations(s, i, end);
                swap(&s[start], &s[i+1]);
                permutations(s, i, end);
        }


}

int main() {
        char s[] = {'A', 'B', 'C', '\0'};
        int n = strlen(s);
        permutations(s, 0, n-1);
}
