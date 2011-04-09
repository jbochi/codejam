#include <stdio.h>
#include <string.h> 

int main() {
    int t;
    scanf("%d", &t);

    int i;
    for (i = 0; i < t; i++) {
        int n, m;
        char paths[5000][1000];
        int new = 0;

        scanf("%d %d", &n, &m);
        int e = 0;
        int j;
        for (j=0; j < n + m; j++) {
            char path[1000];
            scanf("%s", path);

            char subpath[1000];
            int k = 0;
            char c = ' ';
            do {
                c = path[k];
                if ((c == '/' || c == '\0') && (k > 0)) {
                   subpath[k] = '\0';
                   int l;
                   int found = 0;
                   for (l = 0; l < e; l++) {
                       if (strcmp(paths[l], subpath) == 0) {
                            found = -1;
                            break;
                       }
                   }
                   if (!found) {
                       strcpy(paths[e], subpath);
                       //printf("%s:\t%s\n", path, paths[e]);
                       e++;
                       if (j >= n)
                           new++;
                   }
                }
                subpath[k++] = c;
            } while (c != '\0');
        }

        printf("Case #%d: %d\n", i+1, new);
    }

    return 0;
}
