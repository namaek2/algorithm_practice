// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

pair<int, int> a;
pair<int, int> b;

void func(int m)
{
	queue<pair<int, int>> q;

	int vis[302][302];

	memset(vis, 0, sizeof(vis));

	q.push(a);
	vis[a.first][a.second] = 0;

	int dx[8] = { 2, 2, -2, -2, 1, -1, 1, -1 };
	int dy[8] = { 1, -1, 1, -1, 2, 2, -2, -2 };

	while (!q.empty())
	{
	
		pair<int, int> cur = q.front();
		q.pop();

		for (int k = 0; k < 8; k++)
		{
			
			int tx = cur.first + dx[k];
			int ty = cur.second + dy[k];

			if (tx < 0 || ty < 0 || tx >= m || ty >= m)
				continue;

			if (vis[tx][ty] != 0)
				continue;

			if (tx == b.first && ty == b.second)
			{
				vis[tx][ty] = vis[cur.first][cur.second] + 1;
				cout << vis[tx][ty] << "\n";
				return;
			}

			q.push({ tx, ty });
			vis[tx][ty] = vis[cur.first][cur.second] + 1;
		}
	}
	cout << "0\n";
	return;
}

int main(void)
{
	

	int n;
	int m;

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> m;

		int ta, tb, tc, td;
		cin >> ta >> tb;
		cin >> tc >> td;
		a.first = ta;
		a.second = tb;
		b.first = tc;
		b.second = td;

		if (a.first == b.first && a.second == b.second)
			cout << "0\n";
		else
			func(m);

	}

	return 0;
}
