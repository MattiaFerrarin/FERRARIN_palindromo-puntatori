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

    while (*p1 <'a' || *p1 >'z') {
        p1++;
    }
    while (*p2 <'a' || *p2 >'z') {
        p2--;
    }
    while (*p1 == *p2) {
        if (p1-p2>0) {
            printf("palindrome\n");
            return 0;
        }
        p1++;
        p2--;
        while (*p1 <'a' || *p1 >'z') {
            p1++;
        }
        while (*p2 <'a' || *p2 >'z') {
            p2--;
        }
    }
    printf("not a palindrome\n");
    return 0;
}