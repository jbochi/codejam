#include <stdio.h>

int d(char *t, char *f, int i, int j) {
    printf("%d, %d, %c, %c\n", i, j, *(t+i), *(f+j));   
    if (i < 0 || j < 0)
        return 0;    
    else if (*(t + i) != *(f + j))
        return d(t, f, i-1, j);
    else if (j == 0)
        return 1;
    else
        return d(t, f, i-1, j) + d(t, f, i-1, j-1);
}

int main() {
    char t[] = "aabccc";
    char f[] = "abc";
    printf("%d", d((char *) &t, (char *) &f, 6, 2));

    return 0;
}
