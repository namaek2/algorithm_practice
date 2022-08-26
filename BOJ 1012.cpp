// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

bool vis[51][51];
int arr[51][51];

void func(int x, int y)
{
	queue<pair<int, int>> q;
	int temp = 0;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (arr[i][j] == 1 && vis[i][j] != true)
			{
				int dx[4] = { 0, 1, 0, -1 };
				int dy[4] = { 1, 0, -1, 0 };
				q.push({ i, j });
				vis[i][j] = true;

				temp++;

				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();

					for (int u = 0; u < 4; u++)
					{
						int tx = cur.first + dx[u];
						int ty = cur.second + dy[u];

						if (tx < 0 || ty < 0 || tx >= x || ty >= y)
							continue;

						if (vis[tx][ty] != false || arr[tx][ty] != 1)
							continue;

						q.push({ tx, ty });
						vis[tx][ty] = true;
					}
				}
			}
		}
	}
	cout << temp <<"\n";
	return;

}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{

		for (int ta = 0; ta < 51; ta++)
		{
			for (int tb = 0; tb < 51; tb++)
			{
				arr[ta][tb] = 0;
				vis[ta][tb] = false;
			}
		}

		int x, y, k;
		cin >> x >> y >> k;


		for (int j = 0; j < k; j++)
		{
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
		}

		func(x, y);
	}
}
