#include <stdio.h>

int main() {
	int test_cases;
	int test_case;
	scanf("%d\n", &test_cases);
	for (test_case = 1; test_case <= test_cases; test_case++) {
		int steps;
		scanf("%d ", &steps);

		int r_times[2] = {0, 0};
		int pos[2] = {1, 1};
		int t_time = 0;

		int step;
		for (step = 0; step < steps; step++) {
			char robot_name;
			scanf("%c ", &robot_name);
			
			int button;
			scanf("%d", &button);
			
			char space;
			scanf("%c", &space);

			int robot = (robot_name == 'O') ? 0 : 1;
			int other_robot = (robot == 0) ? 1 : 0;

			int distance = abs(button - pos[robot]);
			pos[robot] = button;
			r_times[robot] += distance + 1;
			if (r_times[other_robot] > 0) {
				int delta = r_times[robot] - r_times[other_robot];
				int a_time = (delta > 0) ? delta : 1;
				t_time += a_time;
				r_times[robot] = a_time;
				r_times[other_robot] = 0;
			} else {				
				t_time += distance + 1;
			}
			/*
			printf("%c %d |  %d %d %d\n", robot_name, button,
			                              t_time, 
							              r_times[0], r_times[1]);
			*/
		}

		printf("Case #%d: %d\n", test_case, t_time);
	}
	return 0;
}

