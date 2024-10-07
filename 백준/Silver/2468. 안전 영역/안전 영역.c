#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <memory.h>

int visit[101][101];

int map[101][101];

void dfs(int x, int y, int n, int count)

{

    visit[x][y] = 1;

    if(x+1<n && visit[x+1][y] == 0&& map[x+1][y] > count)

    {

        dfs(x+1,y,n,count);

    }

    if(x-1>=0&&visit[x-1][y] == 0&& map[x-1][y] > count)

    {

        dfs(x-1, y, n, count);

    }

    if(y+1< n&&visit[x][y+1] == 0&&map[x][y+1] > count)

    {

        dfs(x,y+1,n,count);

    }

    if(y-1 >=0&&visit[x][y-1]== 0&&map[x][y-1]>count)

    {

        dfs(x,y-1,n,count);

    }

}

int main(void)

{

    int n =0;

    scanf(" %d",&n);

    int max=0;

    for(int j = 0; j<n; j++)

    {

        for(int k=0; k<n; k++)

        {

            scanf(" %d", &map[k][j]);

            if (max < map[k][j])

            {

                max = map[k][j];

            }

        }

    }

    int result=1;

    for (int m=0; m<max; m++)

    {

        int temp=0;

        while(1)

        {

            int count =0;

            for (int j=0; j<n; j++)

            {

                for(int k=0; k<n; k++)

                {

                    if(visit[k][j]==0 && map[k][j] > m)

                    {

                        count++;

                        dfs(k, j,n, m);

                        break;

                    }

                }

                if(count!=0)

                {

                    break;

                }

            }

            if(count==0)

            {

                break;

            }

            temp++;

        }

        if (result < temp)

        {

            result=temp;

        }

        memset(visit, 0,sizeof(visit));

    }

    printf("%d",result);

}