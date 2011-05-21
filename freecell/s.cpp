#include <stdio.h>

long long int lcd(long long int a, long long int b) {
	int d;
	int min = a > b ? b : a;

	for(d = 2; d<=min; d++) 
		if(((a%d)==0) && ((b%d)==0)) 
			return d;
			
	return 0;
}

int main() {
	int testCases;
	scanf("%d", &testCases);

	for (int testCase = 1; testCase <= testCases; testCase++) {
		printf("Case #%d: ", testCase);
		long long int N;
		int Pd, Pg;
		scanf("%lld %d %d", &N, &Pd, &Pg);

		if ((Pd  < 100 && Pg == 100) || (Pd > 0 && Pg == 0)) {
			printf("Broken");
		} else if (Pd == 0 || N > 100) {
			printf("Possible");
		} else {
			int solved = -1;

			long long int n = Pd;
			long long int d = 100;
			//printf("----%d %d %d\n", N, Pd, Pg);
			while (int div = lcd(n, d)) {				
				n /= div;
				d /= div;				
				//printf("%d %d %d\n", div, n, d);
			}
			
			if (d <= N)
				printf("Possible");
			else
				printf("Broken");
		}		
		printf("\n");
	}
	return 0;
}
