#include <stdio.h>

int main() {
    int n; // number of cases
    int i; // case

    int j; // char
    int k; // i word
    int l; // i word char
    
    char words[1000][20];
    char c;


    scanf("%d\n", &n);

    for (i = 0; i < n; i++) {
        k = 0;
        j = 0;
        l = 0;
        while ((c = getchar())) {
            if (c == ' ' || c == '\n') {
                words[k][l] = '\0';
                if (c == '\n')
                    break;
                k++;
                l = 0;
            } else {
                words[k][l++] = c;
            }
            j++;
	}
        
        printf("Case #%d:", i + 1);

        for (; k >= 0; k--) {
            printf(" %s", words[k]);
        }
        printf("\n");
    }
    return 0;
}
