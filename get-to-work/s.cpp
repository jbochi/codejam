#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
	int C;
	scanf("%d\n", &C);

	for (int testCase = 1; testCase <= C; testCase++) {
		printf("Case #%d:", testCase);

		int N, T;
		scanf("%d %d\n", &N, &T);
		T--;

		int E;
		scanf("%d\n", &E);

		vector<int> employees[N];

		for (int i = 0; i < E; i++) {
			int H, P;
			scanf("%d %d\n", &H, &P);
			employees[H - 1].push_back(P);
		}

		int solution[N];
		int possible = -1;
		for (int i = 0; i < N; i++) {
			int cars;
			if ((i != T) && (!employees[i].empty())) {
				cars = 0;
				int space = 0;

				sort(employees[i].begin(), employees[i].end());
				reverse(employees[i].begin(), employees[i].end());
				for (int j = 0; (j < employees[i].size()) 
					            && possible; j++) {
					//printf("\n %d %d %d %d", i, j, space, cars);
					if (space < 1) {
						cars++;
						if((cars > employees[i].size()) || 
						   (employees[i][cars - 1] == 0)) {
							possible = 0;
							break;
						} else {
							space += employees[i][cars - 1];
						}
					}
					space--;
				}
			} else {
				cars = 0;
			}
			solution[i] = cars;
		}

		if (!possible) {
			printf(" IMPOSSIBLE");
		} else {
			for (int i = 0; i < N; i++) {
				printf(" %d", solution[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
