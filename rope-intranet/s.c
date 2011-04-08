#include <stdio.h>

int main() {
    int t;
    long long as[100000];
    long long bs[100000];
    scanf("%d", &t);
    
    int i;
    for (i = 0; i<t; i++) {
         int n;
         scanf("%d", &n);

         int j;
         int intersections = 0;
         for (j = 0; j<n; j++) {
             scanf("%lld %lld", &as[j], &bs[j]);
             int k;
             for (k = 0; k<j; k++) {
                 if ((as[j] < as[k]) && (bs[j] > bs[k]) ||
                     (as[k] < as[j]) && (bs[k] > bs[j])) {
                     intersections++;
                 }
             }
         }
         
         printf("Case #%d: %d\n", i+1, intersections);
    }
    return 0;
}
