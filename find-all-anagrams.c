https://leetcode.com/problems/find-all-anagrams-in-a-string/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
inline bool all_count(long long arr[]) {
    int k;
    for(k=0; k<26; k++) {
        if (arr[k] != 0)
            break;
    }
    return k==26? true : false;
}

int* findAnagrams(char * s, char * p, int* returnSize){
    int *res = (int*)calloc(sizeof(int), strlen(s));
    int i,j;

    long long *arr = (long long*) calloc(sizeof(long long), 26);
    int count = 0;
    
    for(int k=0; k<strlen(p) ; k++) {
        arr[p[k] - 'a'] += 1;
    }

    i=0;
    j=0;
    while ( j < strlen(s) ) {
        arr[ s[j] - 'a' ] -= 1;
        if( j-i+1 < strlen(p)){
            j++;
            continue;
        } else {
            if( all_count(arr) ) {
                res[count] = i;
                count++;
            }
            
            int temp = s[i] - 'a';
            arr[temp] += 1;
            i++;
            j++;
            continue;
        }
    }
    
    *returnSize = count;
    return res;
}
