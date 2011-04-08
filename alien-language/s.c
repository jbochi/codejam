#include <stdio.h>

int main() {
    int l;
    int d;
    int n;
    scanf("%d %d %d", &l, &d, &n);
    
    int i;
    char words[5000][26];
    for (i=0; i < d; i++) {
        scanf("%s", words[i]);
    } 
    
    char pattern[6500];
    for (i=0; i < n; i++) {
        scanf("%s", pattern);
        
        //fill options matrix
        char options[15][26];
        int j = 0;
        int k = 0;
        int w = 0;
        int in = 0;
        char option = 0;
        do {
            char c = pattern[j++];
            if (c == '(') {
                in = -1;
                option = 0;
            } else if (c == ')') {
                in = 0;
                w++;
            } else {
                if (!in)
                    option = 0;
                options[w][option] = c;
                //printf("%d %d %c\n", w, option, c);
                options[w][++option] = '\0';

                if (!in)
                    w++;
            }
        } while (w < l);


        int n_combinations = 0;
        int combinations[d];
        for (j = 0; j < d; j++)
            combinations[j] = -1;

        for (k = 0; k < d; k++) { //word
            for (w = 0; combinations[k] && w < l; w++) { //letter
                int found = 0;
                for (option = 0; options[w][option] != '\0'; option++) { //option
                     if (words[k][w] == options[w][option]) {
                         found = -1;
                         break;
                     }
                }
                if (!found) {
                     //printf("not %s (%d)\n", words[k], w);
                     combinations[k] = 0;
                     break;
                }
            }
            if (combinations[k]) {
                ++n_combinations;
                //printf("%d: %s\n", n_combinations, words[k]);
            }
        }

        printf("Case #%d: %d\n", i + 1, n_combinations);
    }
    return 0;
}
