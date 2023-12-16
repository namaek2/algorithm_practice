// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int x, y;
char arr[1002][1002];
int vis[1002][1002];
int vis1[1002][1002];
int temp = 0;

void bfs() 
{
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (arr[i][j] == 'F')
			{
				q1.push({ i, j });
				vis[i][j] = 0;
			}

			else if (arr[i][j] == 'J')
			{
				q2.push({ i, j });
				vis1[i][j] = 0;
			}
		}
	}

	while (!q1.empty())
	{
		pair <int, int>	cur = q1.front();
		q1.pop();

		for (int i = 0; i < 4; i++)
		{
			int tx = cur.first + dx[i];
			int ty = cur.second + dy[i];

			if (tx < 0 || ty < 0 || tx >= x || ty >= y)
				continue;

			if (arr[tx][ty] == '#' || vis[tx][ty] != -1)
				continue;

			q1.push({ tx, ty });
			vis[tx][ty] = vis[cur.first][cur.second] + 1;
		}
	}

	while (!q2.empty())
	{
		pair <int, int>	cur = q2.front();
		q2.pop();

		for (int i = 0; i < 4; i++)
		{
			int tx = cur.first + dx[i];
			int ty = cur.second + dy[i];

			if (tx < 0 || ty < 0 || tx >= x || ty >= y)
			{
				cout << vis1[cur.first][cur.second] + 1;
				temp = 1;
				return;
			}

			if (arr[tx][ty] == '#' || vis1[tx][ty] != -1)
				continue;
			
			if (vis[tx][ty] != -1 && vis[tx][ty] <= vis1[cur.first][cur.second] + 1)
				continue;

			q2.push({ tx, ty });
			vis1[tx][ty] = vis1[cur.first][cur.second] + 1;
		}
	}

	return;
}


int main()
{
	cin >> x >> y;
	
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> arr[j][i];

			vis[j][i] = -1;
			vis1[j][i] = -1;
		}
	}

	bfs();

	if (temp == 1)
		return 0;

	cout << "IMPOSSIBLE";

	return 0;
}
