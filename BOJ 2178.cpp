// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int x, y;
int arr[102][102];
int vis[102][102];

void bfs() 
{
	queue<pair<int, int>> q;

	q.push({ 0, 0 });
	vis[0][0] = 1;

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

			if (arr[tx][ty] != 49 || vis[tx][ty] != -1)
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

	for (int i = 0; i < x; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = s[j];
			vis[i][j] = -1;
		}
	}

	bfs();
	
	cout << vis[x-1][y-1];

	return 0;
}
