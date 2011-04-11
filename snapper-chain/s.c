#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    int idxt;
    for (idxt = 0; idxt < t; idxt++) {
        long long n;
        long long k;
        scanf("%lld %lld", &n, &k);
        
        int b[n];
        long long idxn, i;
        for (idxn = 0; idxn < n; idxn++) {
            b[idxn] = 0;
        }

        for (i = 0; i < k; i++) {
            int power = -1;
            for (idxn = 0; power && (idxn < n); idxn++) {
                int tmp;
                if (power) {
                    tmp = b[idxn] ? 0 : -1;
                }
                power = b[idxn];
                b[idxn] = tmp;
                //printf("%lld: %lld -> %d\n", i, idxn, tmp);
            }
        }

        int on = -1;
        for (idxn = 0; idxn < n; idxn++) {
            if (!b[idxn]) {
                on = 0;
                break;
            }
        }

        printf("Case #%d: %s\n", idxt+1, on ? "ON": "OFF");
    }
    return 0;
}
