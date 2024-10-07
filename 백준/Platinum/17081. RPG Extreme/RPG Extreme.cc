#include <bits/stdc++.h>
using namespace std;
char Map[101][101];
int n = 0, m = 0;
int starty = 0;
int startx = 0;
int maxhp = 20;
int Round = 0;
int stop = 0;
struct info
{
	int y;
	int x;
	int hp;
	int exp;
	int lv;
	int att;
	int w;
	int def;
	int a;
	int counto;
	int HR;
	int RE;
	int CO;
	int EX;
	int DX;
	int HU;
	int CU;
};
info player;
struct monster
{
	string name;
	int w;
	int a;
	int hp;
	int exp;
};
monster monmap[101][101];
struct item
{
	char kind;
	string buf;
};
item imap[101][101];
void init(int starty, int startx)
{
	player.y = starty;
	player.x = startx;
	player.hp = maxhp;
}
void itemget(int y, int x)
{
	if (imap[y][x].kind == 'W')
	{
		player.w = stoi(imap[y][x].buf);
	}
	else if (imap[y][x].kind == 'A')
	{
		player.a = stoi(imap[y][x].buf);
	}
	else
	{
		if (player.counto < 4)
		{
			if (imap[y][x].buf == "HR")
			{
				if (player.HR == 0)
				{
					player.HR = 1;
					player.counto++;
				}
			}
			else if (imap[y][x].buf == "RE")
			{
				if (player.RE == 0)
				{
					player.RE = 1;
					player.counto++;
				}
			}
			else if (imap[y][x].buf == "CO")
			{
				if (player.CO == 0)
				{
					player.CO = 1;
					player.counto++;
				}
			}
			else if (imap[y][x].buf == "EX")
			{
				if (player.EX == 0)
				{
					player.EX = 1;
					player.counto++;
				}
			}
			else if (imap[y][x].buf == "DX")
			{
				if (player.DX == 0)
				{
					player.DX = 1;
					player.counto++;
				}
			}
			else if (imap[y][x].buf == "HU")
			{
				if (player.HU == 0)
				{
					player.HU = 1;
					player.counto++;
				}
			}
			else if (imap[y][x].buf == "CU")
			{
				if (player.CU == 0)
				{
					player.CU = 1;
					player.counto++;
				}
			}
		}
	}
	Map[y][x] = '.';
}
void trap()
{
	if (player.DX == 1)
	{
		player.hp--;
	}
	else
	{
		player.hp -= 5;
	}
}
void fight(int y, int x)
{
	int maxmonhp = monmap[y][x].hp;
	if (Map[y][x] == '&')
	{
		if (player.CO == 1 && player.DX == 1)
		{
			monmap[y][x].hp -= max(1, (player.att + player.w) * 3 - monmap[y][x].a);
		}
		if (player.CO == 1 && player.DX == 0)
		{
			monmap[y][x].hp -= max(1, (player.att + player.w) * 2 - monmap[y][x].a);
		}
		if (player.CO == 0)
		{
			monmap[y][x].hp -= max(1, (player.att + player.w) - monmap[y][x].a);
		}
		while (monmap[y][x].hp > 0)
		{
			player.hp -= max(1, monmap[y][x].w - (player.def + player.a));
			if (player.hp <= 0) 
			{
				if (player.RE == 1) 
				{
					player.RE = 0; 
					player.counto--;
					init(starty, startx);
					monmap[y][x].hp = maxmonhp; 
					return; 
				}
				else 
				{
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							cout << Map[i][j];
						}
						cout << '\n';
					}
					cout << "Passed Turns : " << Round << '\n';
					cout << "LV : " << player.lv << '\n';
					cout << "HP : " << 0 << '/' << maxhp << '\n';
					cout << "ATT : " << player.att << '+' << player.w << '\n';
					cout << "DEF : " << player.def << '+' << player.a << '\n';
					cout << "EXP : " << player.exp << '/' << player.lv * 5 << '\n';
					cout << "YOU HAVE BEEN KILLED BY " << monmap[y][x].name << "..";
					stop++;
					return;
				}
			}
			monmap[y][x].hp -= max(1, (player.att + player.w) - monmap[y][x].a); 
		}
		if (player.HR == 1)
		{
			if (maxhp - player.hp <= 3)
			{
				player.hp = maxhp; 
			}
			else 
			{
				player.hp += 3;
			}
		}
		if (player.EX == 1) 
		{
			player.exp += (int)((double)1.2 * (double)monmap[y][x].exp); 
		}
		else 
		{
			player.exp += monmap[y][x].exp; 
		}
		if (player.exp >= player.lv * 5)
		{
			player.lv++; 
			player.exp = 0; 
			player.att += 2; 
			player.def += 2;
			maxhp += 5;
			player.hp = maxhp; 
		}
	}
	else
	{
		if (player.HU == 1)
		{
			player.hp = maxhp;
		}
		if (player.CO == 1 && player.DX == 1)
		{
			monmap[y][x].hp -= max(1, (player.att + player.w) * 3 - monmap[y][x].a);
		}
		if (player.CO == 1 && player.DX == 0)
		{
			monmap[y][x].hp -= max(1, (player.att + player.w) * 2 - monmap[y][x].a);
		}
		if (player.CO == 0)
		{
			monmap[y][x].hp -= max(1, (player.att + player.w) - monmap[y][x].a);
		}
		int count = 0;
		while (monmap[y][x].hp > 0)
		{
			if (player.HU == 1 && count == 0)
			{
				count++;
			}
			else
			{
				player.hp -= max(1, monmap[y][x].w - (player.def + player.a)); 
				if (player.hp <= 0)
				{
					if (player.RE == 1)
					{
						player.RE = 0; 
						player.counto--; 
						init(starty, startx); 
						monmap[y][x].hp = maxmonhp;
						return;
					}
					else 
					{
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
							{
								cout << Map[i][j];
							}
							cout << '\n';
						}
						cout << "Passed Turns : " << Round << '\n';
						cout << "LV : " << player.lv << '\n';
						cout << "HP : " << 0 << '/' << maxhp << '\n';
						cout << "ATT : " << player.att << '+' << player.w << '\n';
						cout << "DEF : " << player.def << '+' << player.a << '\n';
						cout << "EXP : " << player.exp << '/' << player.lv * 5 << '\n';
						cout << "YOU HAVE BEEN KILLED BY " << monmap[y][x].name << "..";
						stop++;
						return;
					}
				}
			}
			monmap[y][x].hp -= max(1, (player.att + player.w) - monmap[y][x].a); 
		}
		if (player.HR == 1) 
		{
			if (maxhp - player.hp <= 3)
			{
				player.hp = maxhp;
			}
			else 
			{
				player.hp += 3; 
			}
		}
		if (player.EX == 1) 
		{
			player.exp += (int)((double)1.2 * (double)monmap[y][x].exp); 
		}
		else 
		{
			player.exp += monmap[y][x].exp; 
		}
		if (player.exp >= player.lv * 5) 
		{
			player.lv++; 
			player.exp = 0;
			player.att += 2;
			player.def += 2;
			maxhp += 5;
			player.hp = maxhp; 
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == player.y && j == player.x)
				{
					cout << '@'; 
				}
				else
				{
					cout << Map[i][j];
				}
			}
			cout << '\n';
		}
		cout << "Passed Turns : " << Round << '\n';
		cout << "LV : " << player.lv << '\n';
		cout << "HP : " << player.hp << '/' << maxhp << '\n';
		cout << "ATT : " << player.att << '+' << player.w << '\n';
		cout << "DEF : " << player.def << '+' << player.a << '\n';
		cout << "EXP : " << player.exp << '/' << player.lv * 5 << '\n';
		cout << "YOU WIN!";
		stop++;
	}
	Map[y][x] = '.'; 
}
void move(char command, int y, int x, int n, int m)
{
	if (command == 'L' && x - 1 >= 0 && Map[y][x - 1] != '#')
	{
		player.x--; 
	}
	else if (command == 'R' && x + 1 < m && Map[y][x + 1] != '#') 
	{
		player.x++; 
	}
	else if (command == 'U' && y - 1 >= 0 && Map[y - 1][x] != '#') 
	{
		player.y--; 
	}
	else if (command == 'D' && y + 1 < n && Map[y + 1][x] != '#')
	{
		player.y++;
	}
	Round++; 
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	player.w = 0;
	player.a = 0;
	player.att = 2; 
	player.def = 2;
	player.lv = 1; 
	player.HR = 0;
	player.RE = 0;
	player.CO = 0;
	player.EX = 0;
	player.DX = 0;
	player.HU = 0;
	player.CU = 0;
	player.counto = 0; 
	cin >> n >> m;
	int mon = 0, tem = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 'M' || Map[i][j] == '&')
			{
				mon++; 
			}
			else if (Map[i][j] == 'B') 
			{
				tem++; 
			}
			else if (Map[i][j] == '@')
			{
				starty = i;
				startx = j; 
			}
		}
	}
	string command = "";
	cin >> command;
	for (int i = 0; i < mon; i++)
	{
		int y = 0;
		int x = 0;
		string name = "";
		int w = 0, a = 0, hp = 0, exp = 0;
		cin >> y >> x >> name >> w >> a >> hp >> exp;
		monmap[y - 1][x - 1].name = name;
		monmap[y - 1][x - 1].w = w;
		monmap[y - 1][x - 1].a = a;
		monmap[y - 1][x - 1].hp = hp;
		monmap[y - 1][x - 1].exp = exp;
	}
	for (int i = 0; i < tem; i++) 
	{
		int y = 0; 
		int x = 0;
		char kind;
		string buf = "";
		cin >> y >> x >> kind >> buf;
		imap[y - 1][x - 1].kind = kind; 
		imap[y - 1][x - 1].buf = buf;
	}
	init(starty, startx); 
	Map[starty][startx] = '.'; 
	for (int i = 0; i < command.length(); i++)
	{
		move(command[i], player.y, player.x, n, m); 
		if (Map[player.y][player.x] == 'B') 
		{
			itemget(player.y, player.x);
		}
		else if (Map[player.y][player.x] == '^')
		{
			trap(); 
			if (player.hp <= 0) 
			{
				if (player.RE == 1)
				{
					player.RE = 0;
					player.counto--; 
					init(starty, startx); 
				}
				else 
				{
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							cout << Map[i][j];
						}
						cout << '\n';
					}
					cout << "Passed Turns : " << Round << '\n';
					cout << "LV : " << player.lv << '\n';
					cout << "HP : " << 0 << '/' << maxhp << '\n';
					cout << "ATT : " << player.att << '+' << player.w << '\n';
					cout << "DEF : " << player.def << '+' << player.a << '\n';
					cout << "EXP : " << player.exp << '/' << player.lv * 5 << '\n';
					cout << "YOU HAVE BEEN KILLED BY " << "SPIKE TRAP" << "..";
					return 0;
				}
			}
		}
		else if (Map[player.y][player.x] == '&')
		{
			fight(player.y, player.x); 
		}
		else if (Map[player.y][player.x] == 'M')
		{
			fight(player.y, player.x);
		}
		if (stop != 0) 
		{
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == player.y && j == player.x)
			{
				cout << '@'; 
			}
			else
			{
				cout << Map[i][j];
			}
		}
		cout << '\n';
	}
	cout << "Passed Turns : " << Round << '\n';
	cout << "LV : " << player.lv << '\n';
	cout << "HP : " << player.hp << '/' << maxhp << '\n';
	cout << "ATT : " << player.att << '+' << player.w << '\n';
	cout << "DEF : " << player.def << '+' << player.a << '\n';
	cout << "EXP : " << player.exp << '/' << player.lv * 5 << '\n';
	cout << "Press any key to continue.";
	return 0;
}