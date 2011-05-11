#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int is_solution(vector<int> v, int K, int N) {
	int count = 1;
	int next = *min_element(v.begin(), v.end());

	while (count <= next && count <= K && N > 0) {
		int index = (count - 1) % N;
		//printf("%d -> %d\n", count, v[index]); 
		if (v[index] == count) {
			N--;
			v.erase(v.begin() + index);
			rotate(v.begin(), v.begin() + index, v.end());
			next = *min_element(v.begin(), v.end());
			count = 1;
		} else {
			count++;
		}
	}

	return N == 0;
}

int solve(vector<int> &v, int K, int N) {
	while (!is_solution(v, K, N)) {
		/*
	    printf("Testing:");
		for (int i = 0; i < N; i++)
			printf(" %d", v[i]);
		printf("\n");
		*/
		next_permutation(v.begin(), v.end());
	}
}

int main() {
	int testCases;
	scanf("%d", &testCases);

	for (int nTest = 1; nTest <= testCases; nTest++) {
		int K;
		scanf("%d", &K);

		int N;
		scanf("%d", &N);

		vector<int> v;

		for (int i = 0; i < N; i++) {
			int temp;
			scanf("%d", &temp);
			v.push_back(temp);
		}

		solve(v, K, N);

		printf("Case #%d:", nTest);
		for (int i = 0; i < N; i++)
			printf(" %d", v[i]);

		printf("\n");
	}
	return 0;
}
