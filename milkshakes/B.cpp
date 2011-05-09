#include <stdio.h>

int i, j;

int main() {
	int testCases;
	scanf("%d", &testCases);

	int caseId;
	for (caseId = 1; caseId <= testCases; caseId++) {
		printf("Case #%d:", caseId);

		int flavors;
		scanf("%d", &flavors);

		int customers;
		scanf("%d", &customers);

		int F[customers][flavors];
		for (i = 0; i < customers; i++) {
			int n;
			scanf("%d", &n);

			for (j = 0; j < flavors; j++) F[i][j] = 0;

			for (j = 0; j < n; j++) {
				int flavor, malted;
				scanf("%d %d", &flavor, &malted);
				
				F[i][flavor-1] = malted + 1;
			}
		}

		int S[flavors];
		for (i = 0; i < flavors; i++) {
			S[i] = 0;
		}

		int possible = -1;
		for (i = 0; (i < customers) && possible; i++) {
			int satisfied = 0;			
			for (j = 0; j < flavors; j++) {
				//printf("\n|%d|%d|%d|%d", i, j, F[i][j], S[j]);
				if (F[i][j] > 0 && (F[i][j] == S[j] + 1)) {
					satisfied = -1;
					break;
				}
			}
			if (!satisfied) {
				//printf("\n%d insatisf", i);
				for (j = 0; j < flavors; j++) {
					if (F[i][j] == 2 && S[j] == 0) {
						S[j] = 1;
						//printf("%d for %d\n", j, i);
						satisfied = -1;
						i = -1;
						break;
					}
				}
				if (!satisfied) {
					possible = 0;
					break;
				}
			}
		}

		if (!possible)
			printf(" IMPOSSIBLE");
		else
			for (i = 0; i < flavors; i++)
				printf(" %d", S[i]);

		printf("\n");
	}
	return 0;
}
