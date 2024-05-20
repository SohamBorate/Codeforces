#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
// Function to compare two characters, used for sorting
int cmpfunc(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}
 
int main() {
    int t;
    scanf("%d", &t);
 
    while (t--) {
        int n;
        char b[200005]; // The length constraint mentioned allows a maximum of 200000 characters.
 
        // Read the input values
        scanf("%d", &n);
        scanf("%s", b);
 
        // Step 1: Identify distinct characters in `b` and sort them to form `r`
        int distinct[26] = {0}; // To count the distinct characters
        for (int i = 0; i < n; ++i) {
            distinct[b[i] - 'a'] = 1;
        }
 
        char r[27]; // Array to store the distinct characters in alphabetical order
        int index = 0;
        for (int i = 0; i < 26; ++i) {
            if (distinct[i]) {
                r[index++] = 'a' + i;
            }
        }
        r[index] = '\0'; // Null-terminate the string
 
        // Step 2: Create the mapping for symmetric replacements
        char map[26]; // map from character to its symmetric counterpart
        int len_r = strlen(r);
        for (int i = 0; i < len_r; ++i) {
            map[r[i] - 'a'] = r[len_r - 1 - i];
        }
 
        // Step 3: Decode the string `b` using the mapping
        for (int i = 0; i < n; ++i) {
            b[i] = map[b[i] - 'a'];
        }
 
        // Print the decoded string
        printf("%s\n", b);
    }
 
    return 0;
}