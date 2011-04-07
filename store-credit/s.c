#include <stdio.h>

int main() {
    int n = 0; //ammount of cases
    int c = 0; //credit
    int i = 0; //number of items
    
    int j;
    int k;
    int items[2000];


    int s1 = 0;
    int s2 = 0;
    int found = 0;

    scanf("%d", &n);
    for (j = 1; j <= n; j++) {
        scanf("%d", &c);
        scanf("%d", &i);
        for (k = 0; k < i; k++) {
            scanf("%d", &items[k]); 
        }
        found = 0;
        for (s1 = 1; !found && (s1 < i); s1++) {
            for (s2 = 0; !found && (s2 < s1); s2++) {
                if (items[s1] + items[s2] == c) {
                    found = -1;
                }
            }
        }
        printf("Case #%d: %d %d\n", j, s2, s1);
    }
    return 0;
}
