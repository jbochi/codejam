#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int testCases;
	scanf("%d", &testCases);

	for (int testId = 1; testId <= testCases; testId++) {
		int P, A, B;
		scanf("%d %d %d", &A, &B, &P);

		int solution = B - A + 1;
		vector<int> v(B + 1, 0);
		for (int i = 0; i < B + 1; i++)
			v[i] = 0;

		for (int i = 2; i <= B; i++) {
			if (v[i] == 0) {
				int in = 0;
				for (int j = i; j <= B; j += i) {
					if (j >= A && i >= P) {
						if ((v[j] == -1) || in) {
							//printf("fora: %d (%d)\n", j, i);
							solution--;
						} else {
							//printf("in: %d (%d)\n", j, i);
						}
						in = -1;
						v[j] = -1;
					} else {
						v[j] = 1;
					}
				}	
			}
		}
		
		printf("Case #%d: %d\n", testId, solution);
	}
	return 0;
}
