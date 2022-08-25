// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int x, y;
int arr[1002][1002];
int vis[1002][1002];

queue<pair<int, int>> q;

void bfs() 
{
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };


	while (!q.empty())
	{
		pair <int, int>	cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int tx = cur.first + dx[i];
			int ty = cur.second + dy[i];

			if (tx < 0 || ty < 0 || tx >= x || ty >= y)
				continue;

			if (arr[tx][ty] == -1 || vis[tx][ty] != -1)
				continue;

			q.push({ tx, ty });
			vis[tx][ty] = vis[cur.first][cur.second] + 1;
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

			if (arr[j][i] == 1)
			{
				q.push({ j, i });
				vis[j][i] = 0;
			}
			else
				vis[j][i] = -1;
		}
	}

	bfs();

	int mx = 0;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			mx = max(vis[i][j], mx);

			if (arr[i][j] == 0 && vis[i][j] == -1)
			{
				cout << "-1";
				return 0;
			}
		}
	}
	cout << mx;

	return 0;
}
