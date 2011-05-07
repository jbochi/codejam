#include <stdio.h>
#include <string.h>

int main() {
	char letters[100];

	int test_cases;
	scanf("%d\n", &test_cases);

	int test_case;
	for (test_case = 1; test_case <= test_cases; test_case++) {
		int i;
		
		int n_c;
		scanf("%d ", &n_c);
		char c[n_c][3];
		for (i = 0; i < n_c; i++)
			scanf("%c%c%c ", &c[i][0], &c[i][1], &c[i][2]);

		int n_d;
		scanf("%d ", &n_d);
		char d[n_d][2];
		for (i = 0; i < n_d; i++)
			scanf("%c%c ", &d[i][0], &d[i][1]);

		i = 0;
		int l;
		scanf("%d ", &l);		
		char in_letter;

		for (; l > 0; l--) {
			scanf("%c", &in_letter);
			letters[i] = in_letter;
			letters[i+1] = '\0';
			i += 1;

			int combined = 0;
			int ic;
			if (i > 1) {
				for (ic = 0; ic < n_c; ic++) {
					if ((letters[i-2] == c[ic][0] && letters[i - 1] == c[ic][1]) ||
						(letters[i-2] == c[ic][1] && letters[i - 1] == c[ic][0])) {
						i = i - 1;
						letters[i-1] = c[ic][2];
						letters[i] = '\0';
						combined = -1;
					}
				}
			}
	
			int id;

			if (!combined) {
				for (id = 0; id < n_d; id++) {
					int a = 0;
					int b = 0;
					int k;
					for (k = 0; k <= i; k++) {
						if (letters[k] == d[id][0]) {
							a = -1;
						} else if (letters[k] == d[id][1]) {
							b = -1;
						}
					}
					if (a && b) {
						letters[0] = '\0';
						i = 0;
					}
				}
			}

			//printf("%c -> %s\n", in_letter, letters);
		}


		scanf("\n");


		printf("Case #%d: [", test_case);

		int k;
		for (k = 0; k < i; k++) {
			printf("%c", letters[k]);
			if (k < i - 1)
				printf(", ");
		}
		printf("]\n");
	}
	return 0;
}
