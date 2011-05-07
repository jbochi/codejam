#include <math.h>
#include <stdio.h>

int main() {
	int cases;
	scanf("%d\n", &cases);

	int n_case;
	for (n_case = 1; n_case <= cases; n_case++) {
		int n;
		scanf("%d\n", &n);

		long long int e[n];
		int i;
		for (i = 0; i < n; i++) {
			scanf("%lld", &e[i]);
		}

		long long int t = -1;
		long long int q = 1;
		long long int il = 0;
	
		for (i = 0; i < n; i++)
			q *= 2;

		//printf("%lld\n", q);

		for (il = 1; il < q - 1; il++) {
			int total = 0;
			int wrong_total = 0;
			int wrong_total2 = 0;
			unsigned long long int mask = il;

			int j;
			for (j = 0; j < n; j++) {
				if (mask & 1) {
					//printf("%lld ", e[j]);
					total += e[j];
					wrong_total ^= e[j];
				} else {
					wrong_total2 ^= e[j];
				}
				mask = mask >> 1;
			}

			if ((wrong_total == wrong_total2) && (total > t)) {
				t = total;
			}
			//printf("\n");
		}	
		
		printf("Case #%d: ", n_case);
		if (t > 0)
			printf("%lld", t);
		else
			printf("NO");

		printf("\n");
	}
	return 0;
}
