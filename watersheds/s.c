#include <stdio.h>

void read_matrix(int *p, int h, int w) {
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < h; j++) {
            scanf("%d", p++);
        }
    }
}

void fill_basins(int *p, int h, int w) {
    int i, j;
    int b = 0;
    for (i = 0; i < w; i++) {
        for (j = 0; j < h; j++) {
            *p = b++;
            p++;
        }
    }
}

void print_basins(int *p, int h, int w) {
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%c", *p + 'a');
            if (j + 1 == w)
                printf("\n");
            else
                printf(" ");
            p++;
        }
    }
}

void join_basins(int *p, int h, int w, int a, int b) {
    int i, j;

    if (a == b)
        return;

    int n = (a < b) ? a : b;
    int m = (a < b) ? b : a;
   
    //printf("Subs %d por %d", m, n);

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (*p == m)
                *p = n;
            else if (*p > m)
                (*p)--;
            p++;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    int c;
    for (c = 0; c < t; c++) { 
	    int h, w;
	    scanf("%d %d\n", &h, &w);

	    int ar[h][w];
            read_matrix((int *) &ar, h, w);
            
            int b[h][w];
            fill_basins((int *) &b, h, w);

            int i, j;
            for (i = 0; i < h; i++) {
                for (j = 0; j < w; j++) {
                    int d;
                    int l = -1;
                    int dl = -1;

                    for (d = 0; d < 4; d++) {
                        int x = i + dx[d];
                        int y = j + dy[d];
                        if ((x >= 0) && (x < h) && (y >= 0) && (y < w)) {
                            int neigh = ar[x][y];
                            if (neigh < ar[i][j] && (neigh < l || l == -1)) {
                                dl = d;
                                l = neigh;
                            }
                        }
                    }

                    if (dl > -1) {
                        //printf("join (%d, %d) com (%d, %d)\n", i, j, i+dx[dl], j+dy[dl]);
                        join_basins((int *) &b, h, w, b[i][j], b[i+dx[dl]][j+dy[dl]]);
                    }
                }
            } 

            printf("Case #%d:\n", c + 1);
            print_basins((int *) &b, h, w);
    }
    return 0;
}
