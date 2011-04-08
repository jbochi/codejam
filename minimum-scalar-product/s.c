#include <stdio.h>
#include <stdlib.h>

int cmp(const void* pa, const void* pb) {
   int a = *(const long long*)pa;
   int b = *(const long long*)pb;
   return a - b;
}


int main() {
    int t;
    int i;
    int j;
    int n;
    long long v1[800];
    long long v2[800];
    int ai, bi;
    int af, bf;

    scanf("%d", &t);
    for (i = 1; i  <= t; i++) {
        scanf("%d", &n);
        for (j = 0; j < n; j++) {
            scanf("%lld", &v1[j]);
        }
        for (j = 0; j < n; j++) {
            scanf("%lld", &v2[j]);
        }
        qsort(v1, n, sizeof(long long), cmp);
        qsort(v2, n, sizeof(long long), cmp);

        long long a;
        long long b;
        ai = 0;
        bi = 0;
        af = n - 1;
        bf = n - 1;
        long long sum = 0;
        int k;
        for (k = 0; k < n; k++) {
            if (-v1[ai] > v1[af])
                a = v1[ai++];
            else
                a = v1[af--];

            if (a < 0) 
                b = v2[bf--];
            else
                b = v2[bi++];
            //printf("%d %d\n", a, b);
            sum += a * b;
        }
        printf("Case #%d: %lld\n", i, sum);
    }
    return 0;
}
