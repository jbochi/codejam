#include <stdio.h>

int main() {
    int l;
    int d;
    int n;
    scanf("%d %d %d", &l, &d, &n);
    
    int i;
    char words[5000][15];
    for (i=0; i < d; i++) {
        scanf("%s", words[i]);
    } 
    
    char pattern[6500];
    for (i=0; i < n; i++) {
        scanf("%s", pattern);
        
        //fill options matrix
        char options[15][15];
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
                options[w][option + 1] = EOF;

                //verifica se existe alguma palavra com esta letra nesta posicao
                for (k = 0; k < d; k++) {
                    if (words[k][w] == c) {
                        option++;
                        break;
                    }
                }
                if (!in)
                    w++;
            }
        } while (w < l);

        //list combinations
        int indexes[l];
        for (j = 0; j < l; j++)
            indexes[j] = 0;

        int done = 0;
        char combination[l];
        int combinations = 0;
        do {
            for (j = 0; j < l; j++) {
                combination[j] = options[j][indexes[j]];
            }
            combination[l] = '\0';

            for (j = 0; j < d; j++) {
                if (strcmp(combination, words[j]) == 0) {
                    combinations++;
                    break;
                }
            }
            //printf("%d: %s\n", combinations, combination);

            // increment indices for next combination
            int next = 0;
            int k = 0;
            do {
                //printf("%d: %d\n", k, indexes[k]);
                indexes[k] += 1;
                if (options[k][indexes[k]] == EOF) {
                    indexes[k++] = 0;
		    if (k == l)
                        done = -1;
                } else {
                    next = -1;
                }
            } while (!next && !done);
        } while (!done);

        printf("Case #%d: %d\n", i + 1, combinations);
    }
    return 0;
}
