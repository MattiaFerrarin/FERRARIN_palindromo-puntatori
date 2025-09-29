#include <stdio.h>
#define MAX_LENGTH 100

int main(void) {
    char str[MAX_LENGTH];
    printf("Write a sentence:");
    fgets(str, MAX_LENGTH, stdin);
    char *p1 = str, *p2;
    while (*p1!='\0') {
        p1++;
    }
    p2 = p1-1;
    p1 = str;
    for (int i=0; i<p2-p1; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
    }

    // Skips ignorable characters before the first letters
    while (*p1 <'a' || *p1 >'z') {
        p1++;
    }
    while (*p2 <'a' || *p2 >'z') {
        p2--;
    }
    // Checks if the two letters are the same
    while (*p1 == *p2) {
        // If the pointers are equal we are finished and since we are still in the loop it's a palindrome
        if (p1-p2>0) {
            printf("palindrome\n");
            // Quit because we found the solution
            return 0;
        }
        // Moves pointers closer
        p1++;
        p2--;
        // Skips ignorable characters
        while (*p1 <'a' || *p1 >'z') {
            p1++;
        }
        while (*p2 <'a' || *p2 >'z') {
            p2--;
        }
    }
    // If we left the loop it wasn't a palindrome
    printf("not a palindrome\n");
    return 0;
}