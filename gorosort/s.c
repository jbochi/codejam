#include <stdio.h>

int main() {
	int tests;
	scanf("%d", &tests);

	int test;
	for (test=1; test <= tests; test++) {
		int n;
		scanf("%d", &n);

		int arr[n];

		int i;
		printf("INPUT: ");
		for (i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			printf("%d ", arr[i]);
		}
		printf("\n");

		int swaps = 0;
		int done;
		do {
			done = -1;
			for (i = 0; i < n; i++) {
				if (arr[i] != i + 1) {
					int temp;
					temp = arr[arr[i] - 1];
					printf("subs %d %d\n", arr[i], arr[arr[i] - 1]);
					arr[arr[i] - 1] = arr[i];
					arr[i] = temp;
					swaps++;
					done = 0;
				}
			}
		} while (!done);

		printf("Case #%d: %d.000000\n", test, swaps * 2);
	}
	return 0;
}
