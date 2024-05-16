#include <bits/stdc++.h>
using namespace std;
int distence(int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main(void)
{
	int num = 0;
	cin >> num;
	while (num--)
	{
		int startx = 0, starty = 0, endx = 0, endy = 0;
		cin >> startx >> starty >> endx >> endy;
		int n = 0;
		int result = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x = 0, y = 0, r = 0;
			cin >> x >> y >> r;
			if (distence(startx, starty, x, y) < r * r && distence(endx, endy, x, y) > r * r)
			{
				result++;
			}
			if (distence(endx, endy, x, y) < r * r && distence(startx, starty, x, y) > r * r)
			{
				result++;
			}
		}
		cout << result << '\n';
	}
	return 0;
}