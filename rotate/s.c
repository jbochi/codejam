#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    int idxt;
    for (idxt = 0; idxt < t; idxt++) {
        int n, k;
        scanf("%d %d\n", &n, &k);
        int board[n][n];

	// input
        int x, y;
        for (y = 0; y < n; y++) {
            for (x = 0; x < n; x++) {
                int b;
                char c = getchar();
                if (c == '.')
                    b = 0;
                else if (c == 'R')
                    b = 1;
                else if (c == 'B')
                    b = 2;
                board[x][y] = b;
            }
            getchar(); // \n
        }

	//rotate
        int rotated[n+k][n+k];
        for (y = n - 1; y >= 0; y--) {
            int ny = n;
            int nx = (n - 1) - y;

            for (x = n - 1; x >= 0; x--) {
                if (board[x][y]) {
                    //printf("(%d, %d) -> (%d, %d)\n", x, y, nx, ny);
                    rotated[nx][--ny] = board[x][y];
                }                    
            }
            for (ny--; ny >= 0; ny--) {
                rotated[nx][ny] = 0;
            }
        }
        
        //print rotated 
        /*
        for (y = 0; y < n; y++) {
            for (x = 0; x < n; x++) {
                printf("%d", rotated[x][y]);
            }
            printf("\n");
        }
        */

        int r = 0;
        int b = 0;
        int last = 0;       
        int c;
        int row;
        
        // horizontal 
        for (y = 0; y < n; y++) {
            last = 0;
            row = 0; 
            for (x = 0; x < n; x++) {
                c = rotated[x][y];
                if (c && (c == last)) {
                    if (++row == k-1) {
                        if (c == 1) {
                            r = -1;
                        } else if (c == 2) {
                            b = -1;
                        }
                    }
                } else {
                    row = 0;
                }
                last = c;
            }
        }

        // vertical 
        for (x = 0; x < n; x++) {
            last = 0;
            row = 0;
            for (y = 0; y < n; y++) {
                c = rotated[x][y];
                if (c && (c == last)) {
                    if (++row == k-1) {
                        if (c == 1) {
                            r = -1;
                        } else if (c == 2) {
                            b = -1;
                        }
                    }
                } else {
                    row = 0;
                }
                last = c;
            }
        }

        // SE
        int ix;
        for (ix = -n; ix < n; ix++) {
            x = ix;
            y = 0;
            last = 0;
            row = 0;
            do {
                c = (x >= 0 && y >= 0 && x < n && y < n) ? rotated[x][y] : 0;
                if (c && (c == last)) {
                    if (++row == k-1) {
                        if (c == 1) {
                            r = -1;
                        } else if (c == 2) {
                            b = -1;
                        }
                    }
                } else {
                    row = 0;
                }
                last = c;
                x++;
                y++;
            } while (y < n);
        }
        
        // SE
        for (ix = 0; ix < (2 * n); ix++) {
            x = ix;
            y = 0;
            last = 0;
            row = 0;
            do {
                c = (x >= 0 && y >= 0 && x < n && y < n) ? rotated[x][y] : 0;
                if (c && (c == last)) {
                    if (++row == k-1) {
                        if (c == 1) {
                            r = -1;
                        } else if (c == 2) {
                            b = -1;
                        }
                     }
                } else {
                     row = 0;
                }
                last = c;
                x--;
                y++;
            } while (y < n);
        }

        char result[10];
        if (r && b)
            strcpy(result, "Both");
        else if (r) 
            strcpy(result, "Red");
        else if (b)
            strcpy(result, "Blue");
        else
            strcpy(result, "Neither");

        printf("Case #%d: %s\n", idxt + 1, result);

    }
    return 0;
}
