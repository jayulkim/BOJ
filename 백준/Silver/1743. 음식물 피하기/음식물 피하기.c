#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

int map[101][101];

int visited[101][101];

int forward[4][2] = {{-1,0}, {0,-1},{1,0},{0,1}};

int count = 1;

void dfs(int y, int x, int n, int m)

{

    visited[y][x] = 1;

    for (int j = 0; j < 4; j++)

    {

        if (forward[j][0] + y < n && forward[j][0] + y >= 0 && forward[j][1] + x < m && forward[j][1] + x >= 0 && map[forward[j][0] + y][forward[j][1] + x] == 1 && visited[forward[j][0] + y][forward[j][1] + x] == 0)

        {

            visited[forward[j][0] + y][forward[j][1] + x] = 1;

            count++;

            dfs(forward[j][0] + y, forward[j][1] + x, n, m);

        }

    }

}

int main(void)

{

    int n = 0, m = 0, k = 0;

    scanf("%d %d %d", &n, &m, &k);

    for(int j = 0; j < k; j++)

    {

        int y = 0, x = 0;

        scanf("%d %d", &y, &x);

        map[y - 1][x - 1] = 1;

    }

    int max = 0;

    for(int j = 0; j < n; j++)

    {

        for(int h = 0; h < m; h++)

        {

            if (map[j][h] == 1 && visited[j][h] == 0)

            {

                dfs(j, h, n, m);

                if (max < count)

                {

                    max = count;

                }

                count = 1;

            }

        }

    }

    printf("%d", max);

    return 0;

}